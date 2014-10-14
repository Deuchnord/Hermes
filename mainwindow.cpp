#include "mainwindow.h"
#include "produititem.h"
#include "gestionmagasinsdialog.h"
#include "aboutdialog.h"
#include "settingsdialog.h"
#include "ui_mainwindow.h"

#include <QSpacerItem>
#include <QWidget>
#include <QListWidgetItem>
#include <QPixmap>
#include <QSpacerItem>
#include <QDate>
#include <QMessageBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDir>
#include <QFile>
#include <QDataStream>
#include <QList>
#include <QDesktopServices>
#include <QUrl>
#include <QtXml/QDomDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    saveOnQuit = true;

    version = "0.6";

    searchBox = new QLineEdit(this);
    searchBox->addAction(QIcon(":/icons/icon-search.png"), QLineEdit::LeadingPosition);
    searchBox->setPlaceholderText(tr("Rechercher..."));
    searchBox->setClearButtonEnabled(true);

    connect(searchBox, SIGNAL(textChanged(QString)), SLOT(searchProduit(QString)));

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(searchBox);

    // Migration des fichiers si l'utilisateur vient d'une version antérieure à la 0.3
    QDir dir(QDir::homePath()+"/.deuchnord-hermes");
    if(dir.exists(QDir::homePath()+"/.deuchnord-hermes"))
        dir.rename(QDir::homePath()+"/.deuchnord-hermes", QDir::homePath()+"/deuchnord-hermes");
    if(QFile::exists(QDir::homePath()+"/hermes.hrms"))
        QFile::rename(QDir::homePath()+"/hermes.hrms", QDir::homePath()+"/deuchnord-hermes/products.hrms");

    // Récupération de la configuration
    settings = new QSettings("Deuchnord", "Hermes");
    QString placeSave = settings->value("placeSave").toString();
    if(placeSave == "")
    {
        settings->setValue("placeSave", QDir::homePath());
        placeSave = settings->value("placeSave").toString();
    }

    QFile saveFile(placeSave + "/deuchnord-hermes/products.hrms");
    QDataStream content(&saveFile);
    content.setVersion(QDataStream::Qt_5_0);

    if(saveFile.open(QFile::ReadOnly))
    {
        QList<ProduitInfo> listInfoProd;
        content >> listInfoProd;

        for(ProduitInfo i : listInfoProd)
            ajouterProduit(new ProduitItem(this, i.nomProduit, i.dateAchat, i.dateFinGarantie, i.image, i.indexMagasin, i.enSAV, i.factures, i.garanties));
    }

    if(ui->listeProduits->count() > 0)
        ui->listeProduits->item(0)->setSelected(true);
    else
        ui->actionSupprimerProduit->setEnabled(false);

    // Recherche de nouvelle version :
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dlVersionFinished(QNetworkReply*)));

#ifdef Q_OS_LINUX
    QString os = "linux";
#endif
#ifdef Q_OS_WIN32
    QString os = "windows";
#endif

    manager->get(QNetworkRequest(QUrl("http://hermes.deuchnord.tk/version.php?os="+os)));
}

void MainWindow::dlVersionFinished(QNetworkReply *reply)
{
    QString versionAvailable = reply->readAll();
    if(versionAvailable != "" && version != versionAvailable)
    {
        ui->statusBar->showMessage(tr("Une nouvelle version (%1) est disponible !", "%1 represents the number of the new version (for instance: 0.4.1)").arg(versionAvailable));
        QPushButton* btnUpdate = new QPushButton(tr("Télécharger la nouvelle version"));
        connect(btnUpdate, SIGNAL(clicked()), this, SLOT(dlNewVersionBtnClicked()));
        ui->statusBar->addPermanentWidget(btnUpdate);
    }
}

void MainWindow::dlNewVersionBtnClicked()
{
    QDesktopServices::openUrl(QUrl("http://hermes.deuchnord.tk"));
}

void MainWindow::searchProduit(QString search)
{
    if(search != "")
    {
        for(int i = 0; i < ui->listeProduits->count(); i++)
        {
            ProduitItem* item = (ProduitItem*) ui->listeProduits->itemWidget(ui->listeProduits->item(i));
            ProduitInfo prod = item->getProduitInfo();

            // On cache les produits qui ne correspondent pas
            if(prod.nomProduit.contains(search, Qt::CaseInsensitive))
                ui->listeProduits->item(i)->setHidden(false);
            else
                ui->listeProduits->item(i)->setHidden(true);
        }
    }
    else
    {
        // Si la zone de recherche est vide, on affiche tout
        for(int i = 0; i < ui->listeProduits->count(); i++)
            ui->listeProduits->item(i)->setHidden(false);
    }

    updateStatusMessage();
}

void MainWindow::on_actionNouveauProduit_triggered()
{
    ProduitItem *prod = new ProduitItem(this, tr("Nouveau produit", "Showed in the field \"Name\" in the product information window by default."), QDate::currentDate(), QDate::currentDate().addYears(1));
    prod->openDialog(true);
    QListWidgetItem* item = ajouterProduit(prod);
    item->setSelected(true);
    connect(prod, SIGNAL(deleteAsked()), SLOT(deleteAsked()));
    ui->actionSupprimerProduit->setEnabled(true);
}

void MainWindow::deleteAsked()
{
    on_actionSupprimerProduit_triggered(true);
}

void MainWindow::on_actionSupprimerProduit_triggered(bool dontAskConfirm)
{
    if(ui->listeProduits->selectedItems().count() == 1)
    {
        QListWidgetItem *item = ui->listeProduits->selectedItems()[0];

        int answer;
        if(!dontAskConfirm)
            answer = QMessageBox::question(this, tr("Supprimer le produit"), tr("Êtes-vous sûr de vouloir supprimer ce produit ?\nCette action n'est pas réversible."), QMessageBox::Yes | QMessageBox::No);
        else
            answer = QMessageBox::Yes;

        if(answer == QMessageBox::Yes)
        {
            ui->listeProduits->setCurrentRow(ui->listeProduits->row(item));

            // Étape 1 : on vérifie si le magasin du produit est encore utilisé par d'autres produits
            ProduitItem prodToRemove = ((ProduitItem) ui->listeProduits->itemWidget(item));
            int manufacturer = prodToRemove.getMagasin();
            bool manufacturerIsUsedByAnotherProduct = false;
            for(int i = 0; i < ui->listeProduits->count(); i++) {

                if(i != ui->listeProduits->currentRow()) {

                    QListWidgetItem *itemProd = ui->listeProduits->item(i);
                    ProduitItem prod = (ProduitItem) ui->listeProduits->itemWidget(itemProd);
                    if(prod.getMagasin() == manufacturer)
                        manufacturerIsUsedByAnotherProduct = true;

                }

            }

            // Si le magasin n'est plus utilisé, on le supprime
            // TODO écrire le code correspondant

            // Étae 2 : on suppprime le produit
            ui->listeProduits->removeItemWidget(item);

            delete item;

            if(ui->listeProduits->count() == 0)
                ui->actionSupprimerProduit->setEnabled(false);

            updateStatusMessage();
        }
    }
}

void MainWindow::on_actionGererMagasins_triggered()
{
    GestionMagasinsDialog *dialog = new GestionMagasinsDialog(this);
    dialog->setModal(true);
    dialog->show();
    connect(dialog, SIGNAL(magasinDeleted(int)), SLOT(magasinDeleted(int)));
}

void MainWindow::magasinDeleted(int indexMagasin)
{
    // Si un magasin a été supprimé, on change le magasin pour une valeur vide.

    for(int i = 0; i < ui->listeProduits->count(); i++)
    {
        ProduitItem* item = (ProduitItem*) ui->listeProduits->itemWidget(ui->listeProduits->item(i));
        if(item->getMagasin() == indexMagasin)
            item->setMagasin(-1);
        if(item->getMagasin() > indexMagasin)
            item->setMagasin(item->getMagasin()-1);
    }
}

QListWidgetItem* MainWindow::ajouterProduit(ProduitItem *produit)
{
    QListWidgetItem *widgetItem = new QListWidgetItem();
    widgetItem->setSizeHint(QSize(0, 128));
    ui->listeProduits->addItem(widgetItem);
    ui->listeProduits->setItemWidget(widgetItem, produit);

    updateStatusMessage();

    return widgetItem;
}


void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog *settingsDialog = new SettingsDialog(this);
    settingsDialog->setModal(true);
    settingsDialog->show();

    connect(settingsDialog, SIGNAL(dontSaveOnQuit()), SLOT(settings_dontSaveOnQuit()));
}

void MainWindow::settings_dontSaveOnQuit()
{
    saveOnQuit = false;
}

void MainWindow::on_actionAPropos_triggered()
{
    AboutDialog *dialog = new AboutDialog(this, version);
    dialog->setModal(true);
    dialog->show();
}

void MainWindow::on_actionReportBug_triggered()
{
    QDesktopServices::openUrl(QUrl("https://sourceforge.net/p/deuchnord-hermes/bugs/"));
}

void MainWindow::on_actionAide_triggered()
{
    QDesktopServices::openUrl(QUrl("http://hermes.deuchnord.tk/help/"));
}

Ui::MainWindow *MainWindow::getUI()
{
    return ui;
}

void MainWindow::updateStatusMessage()
{
    int nb = 0;
    for(int i = 0; i < ui->listeProduits->count(); i++)
        if(!ui->listeProduits->item(i)->isHidden())
            nb++;

    ui->statusBar->showMessage(tr("%n produit(s) affiché(s).", "", nb));
}

MainWindow::~MainWindow()
{
    // Enregistrement de la configuration
    if(saveOnQuit)
    {
        QString place = settings->value("placeSave").toString();
        QDir dir(place+"/deuchnord-hermes");
        if(!dir.exists())
            dir.mkdir(place+"/deuchnord-hermes");

        QFile saveFile(place+"/deuchnord-hermes/products.hrms");
        QDataStream content(&saveFile);
        content.setVersion(QDataStream::Qt_5_0);
        QList<ProduitInfo> listProd;

        if(saveFile.open(QFile::WriteOnly))
        {
            for(int i = 0; i < ui->listeProduits->count(); i++)
            {
                ProduitItem* item = (ProduitItem*) ui->listeProduits->itemWidget(ui->listeProduits->item(i));
                ProduitInfo prod = item->getProduitInfo();
                listProd << prod;
            }
        }

        content << listProd;

        saveFile.close();
    }

    delete ui;
}
