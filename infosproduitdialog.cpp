#include "infosproduitdialog.h"
#include "ui_infosproduitdialog.h"

#include <QDate>
#include <QDir>
#include <QFile>
#include <QtXml/QDomDocument>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>
#include <QTransform>

InfosProduitDialog::InfosProduitDialog(QWidget *parent, QString nomProduit, QDate dateAchat, QDate dateFinGarantie, QPixmap image, int indexMagasin, bool enSAV, QHash<QString, QByteArray> facturePDF, QHash<QString, QByteArray> garantiePDF) :
    QDialog(parent),
    ui(new Ui::InfosProduitDialog)
{
    ui->setupUi(this);
    parentWidget = parent;

    // Récupération de la liste des magasins enregistrés
    QFile fichierMagasins(QDir::homePath()+"/.deuchnord-hermes/manufacturers.xml");
    fichierMagasins.open(QFile::ReadOnly);
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
                ui->comboMagasin->addItem(manufacturer.firstChild().toText().data());

            node = node.nextSibling();
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer la liste des magasins.\nLes avez-vous enregistrés ?");
    }

    // Remplissage des données
    ui->txtNom->setText(nomProduit);
    ui->dateAchat->setDate(dateAchat);
    ui->dateFinGarantie->setDate(dateFinGarantie);
    ui->comboMagasin->setCurrentIndex(indexMagasin);
    ui->checkSAV->setChecked(enSAV);
    ui->image->setPixmap(image);
    this->image = image;

    // Factures & garanties
    this->facturePDF = facturePDF;
    this->garantiePDF = garantiePDF;
    for(QString i : this->facturePDF.keys())
    {
        ui->listFactures->addItem(i);
    }
    for(QString i : this->garantiePDF.keys())
    {
        ui->listGaranties->addItem(i);
    }

    ui->txtNom->setFocus();
    ui->listFactures->setCurrentItem(ui->listFactures->item(0));
    ui->listGaranties->setCurrentItem(ui->listGaranties->item(0));
}

void InfosProduitDialog::on_btnImageParcourir_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Sélectionnez une image", "", "Images supportées (*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm)");
    if(filename != "")
    {
        image = QPixmap(filename);
        image = image.scaled(QSize(128, 128), Qt::KeepAspectRatio);
        ui->image->setPixmap(image);
    }
}

void InfosProduitDialog::on_btnImageSupprimer_clicked()
{
    image = QPixmap(":/images/no-picture.jpg");
    ui->image->setPixmap(image);
}

void InfosProduitDialog::on_btnAjoutFacture_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Sélectionnez une facture", "", "Fichiers PDF (*.pdf);;Image (*.jpg *.jpeg *.png)");
    if(fileName != "")
    {
        QFile fichier(fileName);
        QFileInfo infoFile(fichier.fileName());
        fichier.open(QFile::ReadOnly);
        if(fichier.isReadable())
        {
            QByteArray contenuFichier = fichier.readAll();
            fichier.close();

            facturePDF.insert(infoFile.fileName(), contenuFichier);
            ui->listFactures->addItem(infoFile.fileName());
        }
        else
            QMessageBox::critical(this, "Erreur", "Impossible de lire le fichier "+fichier.fileName()+"\nVérifiez qu'il est bien accessible en lecture et réessayez.");
    }
}

void InfosProduitDialog::on_listFactures_currentRowChanged()
{
    ui->btnSupprFacture->setEnabled(true);
}

void InfosProduitDialog::on_listFactures_itemDoubleClicked(QListWidgetItem *item)
{
    QByteArray contentFile = facturePDF.value(item->text());
    QFile tempFile(QDir::tempPath()+"/"+item->text());
    tempFile.open(QFile::WriteOnly);
    tempFile.write(contentFile);
    tempFile.close();
    QDesktopServices::openUrl(QUrl(tempFile.fileName()));
}

void InfosProduitDialog::on_btnSupprFacture_clicked()
{
    if(QMessageBox::question(this, "Hermès", "Voulez-vous vraiment supprimer cette facture ?\nCette action n'est pas réversible.", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        QListWidgetItem *item = ui->listFactures->selectedItems().value(0);
        facturePDF.remove(item->text());
        delete item;
    }

    if(ui->listFactures->count() == 0)
        ui->btnSupprFacture->setEnabled(false);
}

void InfosProduitDialog::on_btnAjoutGarantie_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Sélectionnez une fiche garantie", "", "Fichiers PDF (*.pdf);;Image (*.jpg *.jpeg *.png)");
    if(fileName != "")
    {
        QFile fichier(fileName);
        QFileInfo infoFile(fichier.fileName());
        fichier.open(QFile::ReadOnly);
        if(fichier.isReadable())
        {
            QByteArray contenuFichier = fichier.readAll();
            fichier.close();

            garantiePDF.insert(infoFile.fileName(), contenuFichier);
            ui->listGaranties->addItem(infoFile.fileName());
        }
        else
            QMessageBox::critical(this, "Erreur", "Impossible de lire le fichier "+fichier.fileName()+"\nVérifiez qu'il est bien accessible en lecture et réessayez.");
    }
}

void InfosProduitDialog::on_listGaranties_currentRowChanged()
{
    ui->btnSupprGarantie->setEnabled(true);
}

void InfosProduitDialog::on_listGaranties_itemDoubleClicked(QListWidgetItem *item)
{
    QByteArray contentFile = garantiePDF.value(item->text());
    QFile tempFile(QDir::tempPath()+"/"+item->text());
    tempFile.open(QFile::WriteOnly);
    tempFile.write(contentFile);
    tempFile.close();
    QDesktopServices::openUrl(QUrl(tempFile.fileName()));
}

void InfosProduitDialog::on_btnSupprGarantie_clicked()
{
    if(QMessageBox::question(this, "Hermès", "Voulez-vous vraiment supprimer cette fiche garantie ?\nCette action n'est pas réversible.", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        QListWidgetItem *item = ui->listGaranties->selectedItems().value(0);
        garantiePDF.remove(item->text());
        delete item;
    }

    if(ui->listGaranties->count() == 0)
        ui->btnSupprGarantie->setEnabled(false);
}

// Bouton "OK"

void InfosProduitDialog::on_buttonBox_accepted()
{
    getParentItem()->setNomProduit(ui->txtNom->text());
    getParentItem()->setDateAchat(ui->dateAchat->date());
    getParentItem()->setDateFinGarantie(ui->dateFinGarantie->date());
    getParentItem()->setImage(this->image);
    getParentItem()->setMagasin(ui->comboMagasin->currentIndex());
    getParentItem()->setEnSAV(ui->checkSAV->isChecked());
    getParentItem()->setFactures(this->facturePDF);
    getParentItem()->setGaranties(this->garantiePDF);
}

ProduitItem* InfosProduitDialog::getParentItem()
{
    return static_cast<ProduitItem*>(this->parentWidget);
}

InfosProduitDialog::~InfosProduitDialog()
{
    delete ui;
}
