#include "mainwindow.h"
#include "produititem.h"
#include "gestionmagasinsdialog.h"
#include "aboutdialog.h"
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    version = "0.1";

    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Rechercher...");
    searchBox->setToolTip("Recherchez un produit à partir de son nom.\nLa casse n'est pas prise en compte.");
    searchBox->setClearButtonEnabled(true);

    connect(searchBox, SIGNAL(textChanged(QString)), SLOT(searchProduit(QString)));

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(searchBox);

    // Récupération de la configuration

    QFile saveFile(QDir::homePath()+"/hermes.hrms");
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

    ui->statusBar->hide();
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
}

void MainWindow::on_actionNouveauProduit_triggered()
{
    QFile fichierMagasins(QDir::homePath()+"/.deuchnord-hermes/manufacturers.xml");
    fichierMagasins.open(QFile::ReadOnly);
    int nbMagasins = 0;

    if(fichierMagasins.isOpen())
    {
        QString contenuFichier = fichierMagasins.readAll();
        fichierMagasins.close();

        QDomDocument dom;
        dom.setContent(contenuFichier);
        QDomElement root = dom.firstChildElement();
        QDomElement manufacturer;
        QDomNode node = root.firstChild();

        while(!node.isNull())
        {
            manufacturer = node.toElement();
            if(manufacturer.tagName() == "manufacturer")
                nbMagasins++;

            node = node.nextSibling();
        }
    }

    if(nbMagasins == 0)
    {
        QMessageBox::critical(this, "Erreur", "Aucun magasin ne semble avoir été enregistré.\nVeuillez les enregistrer avant d'entrer vos produits.");
        ui->actionGererMagasins->trigger();
    }
    else
    {
        ProduitItem *prod = new ProduitItem(this, "Nouveau produit", QDate::currentDate(), QDate::currentDate().addYears(1));
        prod->openDialog(true);
        QListWidgetItem* item = ajouterProduit(prod);
        item->setSelected(true);
        connect(prod, SIGNAL(deleteAsked()), SLOT(deleteAsked()));
        ui->actionSupprimerProduit->setEnabled(true);
    }
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
            answer = QMessageBox::question(this, "Supprimer le produit", "Êtes-vous sûr de vouloir supprimer ce produit ?\nCette action n'est pas réversible.", QMessageBox::Yes | QMessageBox::No);
        else
            answer = QMessageBox::Yes;

        if(answer == QMessageBox::Yes)
        {
            ui->listeProduits->setCurrentRow(ui->listeProduits->row(item));
            ui->listeProduits->removeItemWidget(item);

            delete item;

            if(ui->listeProduits->count() == 0)
                ui->actionSupprimerProduit->setEnabled(false);
        }
    }
}

void MainWindow::on_actionGererMagasins_triggered()
{
    GestionMagasinsDialog *dialog = new GestionMagasinsDialog(this);
    dialog->setModal(true);
    dialog->show();
}

QListWidgetItem* MainWindow::ajouterProduit(ProduitItem *produit)
{
    QListWidgetItem *widgetItem = new QListWidgetItem();
    widgetItem->setSizeHint(QSize(0, 128));
    ui->listeProduits->addItem(widgetItem);
    ui->listeProduits->setItemWidget(widgetItem, produit);

    //ui->statusBar->showMessage(QString::number(ui->listeProduits->count())+" produits affichés.");

    return widgetItem;
}

void MainWindow::on_actionAPropos_triggered()
{
    AboutDialog *dialog = new AboutDialog(this, version);
    dialog->setModal(true);
    dialog->show();
}

void MainWindow::on_actionAide_triggered()
{
    QDesktopServices::openUrl(QUrl("http://hermes.deuchnord.tk/help/"));
}

Ui::MainWindow *MainWindow::getUI()
{
    return ui;
}

MainWindow::~MainWindow()
{
    // Enregistrement de la configuration
    QFile saveFile(QDir::homePath()+"/hermes.hrms");
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

    delete ui;
}

