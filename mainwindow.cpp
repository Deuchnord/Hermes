#include "mainwindow.h"
#include "produititem.h"
#include "gestionmagasinsdialog.h"
#include "aboutdialog.h"
#include "ui_mainwindow.h"

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
    ProduitItem *prod = new ProduitItem(this, "Nouveau produit", QDate::currentDate(), QDate::currentDate().addYears(1));
    prod->openDialog();
    ajouterProduit(prod);
}

void MainWindow::on_actionSupprimerProduit_triggered()
{
    if(ui->listeProduits->selectedItems().count() == 1)
    {
        QListWidgetItem *item = ui->listeProduits->selectedItems()[0];
        if(QMessageBox::question(this, "Supprimer le produit", "Êtes-vous sûr de vouloir supprimer ce produit ?\nCette action n'est pas réversible.", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        {
            ui->listeProduits->removeItemWidget(item);
            delete item;
        }
    }
}

void MainWindow::on_actionGererMagasins_triggered()
{
    GestionMagasinsDialog *dialog = new GestionMagasinsDialog(this);
    dialog->setModal(true);
    dialog->show();
}

void MainWindow::ajouterProduit(ProduitItem *produit)
{
    QListWidgetItem *widgetItem = new QListWidgetItem();
    widgetItem->setSizeHint(QSize(0, 128));
    ui->listeProduits->addItem(widgetItem);
    ui->listeProduits->setItemWidget(widgetItem, produit);

    //ui->statusBar->showMessage(QString::number(ui->listeProduits->count())+" produits affichés.");
}

void MainWindow::on_listeProduits_currentRowChanged()
{
    ui->actionSupprimerProduit->setEnabled(true);
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

