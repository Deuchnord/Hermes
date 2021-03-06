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
#include <QSettings>

#include <iostream>

InfosProduitDialog::InfosProduitDialog(QWidget *parent, QWidget *mainWindow, QString nomProduit, QDate dateAchat, QDate dateFinGarantie, QPixmap image, int indexMagasin, bool enSAV, QHash<QString, QByteArray> facturePDF, QHash<QString, QByteArray> garantiePDF) :
    QDialog(mainWindow),
    ui(new Ui::InfosProduitDialog)
{
    ui->setupUi(this);
    parentWidget = parent;

    // Récupération de la liste des magasins enregistrés
    QSettings *settings = new QSettings("Deuchnord", "Hermes");
    QFile fichierMagasins(settings->value("placeSave").toString()+"/deuchnord-hermes/manufacturers.xml");
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

    // Remplissage des données
    ui->txtNom->setText(nomProduit);
    ui->dateAchat->setDate(dateAchat);

    if(dateFinGarantie != QDate(1970, 1, 1))
        ui->dateFinGarantie->setDate(dateFinGarantie);
    else
    {
        ui->dateFinGarantie->setDate(QDate::currentDate().addYears(1));
        ui->checkGarantieAVie->setChecked(true);
    }

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

#if !defined Q_OS_LINUX
    // Le bouton ne sera pas disponible sur les systèmes autres que GNU/Linux
    ui->btnScannerFacture->hide();
    ui->btnScannerGarantie->hide();
#endif
}

void InfosProduitDialog::on_btnImageParcourir_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Sélectionnez une image"), "", tr("Images supportées")+" (*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm)");
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Sélectionnez une facture"), "", tr("Fichiers supportés")+" (*.pdf *.jpg *.jpeg *.png);;"+tr("Fichiers PDF")+" (*.pdf);;"+tr("Images")+" (*.jpg *.jpeg *.png)");
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
            QMessageBox::critical(this, tr("Erreur"), tr("Impossible de lire le fichier %1\nVérifiez qu'il est bien accessible en lecture et réessayez.", "%1 represents the file name").arg(fichier.fileName()));
    }
}

void InfosProduitDialog::on_btnScannerFacture_clicked()
{
    // Ne fonctionne que sous Linux pour le moment. Dépendances : sane et imagemagick

    ScannerDialog *dialog = new ScannerDialog(this);
    dialog->setModal(true);
    dialog->show();

    connect(dialog, SIGNAL(accepted()), SLOT(on_factureScanned()));
}

void InfosProduitDialog::on_factureScanned()
{
    QString fileName = QDir::tempPath()+"/output.pdf";
    QFile::rename(fileName, QDir::tempPath()+"/Facture.pdf");
    fileName = QDir::tempPath()+"/Facture.pdf";

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
        QMessageBox::critical(this, tr("Erreur"), tr("Une erreur s'est produite lors de l'ajout de votre document numérisé.\nVous pouvez toujours ajouter le document manuellement, il se trouve ici : %1", "%1 represents the place of the file in the temp directory").arg(fileName));
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
    QDesktopServices::openUrl(QUrl("file:///"+tempFile.fileName()));
}

void InfosProduitDialog::on_btnSupprFacture_clicked()
{
    if(QMessageBox::question(this, tr("Hermès"), tr("Voulez-vous vraiment supprimer cette facture ?\nCette action n'est pas réversible."), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Sélectionnez une fiche garantie"), "", tr("Fichiers supportés")+" (*.pdf *.jpg *.jpeg *.png);;"+tr("Fichiers PDF")+" (*.pdf);;"+tr("Images")+" (*.jpg *.jpeg *.png)");
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
            QMessageBox::critical(this, tr("Erreur"), tr("Impossible de lire le fichier %1\nVérifiez qu'il est bien accessible en lecture et réessayez.", "%1 represents the file name").arg(fichier.fileName()));
    }
}

void InfosProduitDialog::on_btnScannerGarantie_clicked()
{
    // Ne fonctionne que sous Linux pour le moment. Dépendances : libsane et imagemagick
    ScannerDialog *dialog = new ScannerDialog(this);
    dialog->setModal(true);
    dialog->show();

    connect(dialog, SIGNAL(accepted()), SLOT(on_garantieScanned()));
}

void InfosProduitDialog::on_garantieScanned()
{
    QString fileName = QDir::tempPath()+"/output.pdf";
    QFile::rename(fileName, QDir::tempPath()+"/Garantie.pdf");
    fileName = QDir::tempPath()+"/Garantie.pdf";

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
        QMessageBox::critical(this, tr("Erreur"), tr("Une erreur s'est produite lors de l'ajout de votre document numérisé.\nVous pouvez toujours ajouter le document manuellement, il se trouve ici : %1", "%1 represents the place of the file in the temp directory").arg(fileName));
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
    QDesktopServices::openUrl(QUrl("file:///"+tempFile.fileName()));
}

void InfosProduitDialog::on_btnSupprGarantie_clicked()
{
    if(QMessageBox::question(this, tr("Hermès"), tr("Voulez-vous vraiment supprimer cette fiche garantie ?\nCette action n'est pas réversible."), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
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

    if(!ui->checkGarantieAVie->isChecked())
        getParentItem()->setDateFinGarantie(ui->dateFinGarantie->date());
    else
        getParentItem()->setDateFinGarantie(QDate(1970, 1, 1));

    getParentItem()->setImage(this->image);

    QSettings *settings = new QSettings("Deuchnord", "Hermes");
    QFile fichierMagasins(settings->value("placeSave").toString()+"/deuchnord-hermes/manufacturers.xml");
    bool manufacturerAllreadyExists = false;
    QDomDocument dom;
    QDomElement root, manufacturer;
    QDomNode node;

    if(fichierMagasins.open(QFile::ReadOnly)) {

        QString contenuFichier = fichierMagasins.readAll();
        fichierMagasins.close();

        dom.setContent(contenuFichier);
        root = dom.firstChildElement();
        node = root.firstChild();

        while(!node.isNull())
        {
            manufacturer = node.toElement();
            if(manufacturer.tagName() == "manufacturer")
                if(ui->comboMagasin->currentText() == manufacturer.firstChild().toText().data())
                    manufacturerAllreadyExists = true;

            node = node.nextSibling();
        }
    }

    if(!manufacturerAllreadyExists) {

        dom = QDomDocument("manufacturers");
        root = dom.createElement("manufacturers");
        dom.appendChild(root);

        // Boucle d'enregistrement des éléments du combo
        for(int i = 0; i < ui->comboMagasin->count(); i++) {

            QDomElement domManufacturer = dom.createElement("manufacturer");
            root.appendChild(domManufacturer);
            QDomText textManufacturer = dom.createTextNode(ui->comboMagasin->itemText(i));
            domManufacturer.appendChild(textManufacturer);

        }

        // Enregistrement du nouveau magasin
        QDomElement domNewManufacturer = dom.createElement("manufacturer");
        root.appendChild(domNewManufacturer);
        QDomText textNewManufacturer = dom.createTextNode(ui->comboMagasin->currentText());
        domNewManufacturer.appendChild(textNewManufacturer);

        // Enregistrement du fichier XML
        QFile fileManufacturers(settings->value("placeSave").toString()+"/deuchnord-hermes/manufacturers.xml");
        if(fileManufacturers.open(QFile::WriteOnly)) {

            fileManufacturers.write(dom.toString().toUtf8());
            fileManufacturers.close();

        }

        getParentItem()->setMagasin(ui->comboMagasin->count());

    }

    else
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

void InfosProduitDialog::on_checkGarantieAVie_toggled(bool checked)
{
    if(checked)
        ui->dateFinGarantie->setEnabled(false);
    else
        ui->dateFinGarantie->setEnabled(true);
}
