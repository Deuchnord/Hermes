#include "produititem.h"
#include "ui_produititem.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QBuffer>
#include <manufacturersmanager.h>

QDataStream &operator <<(QDataStream &out, const ProduitInfo &prod)
{
    out << prod.nomProduit << prod.dateAchat << prod.dateFinGarantie << prod.image << prod.indexMagasin << prod.enSAV << prod.factures << prod.garanties;

    return out;
}

QDataStream &operator >>(QDataStream &in, ProduitInfo &prod)
{
    in >> prod.nomProduit >> prod.dateAchat >> prod.dateFinGarantie >> prod.image >> prod.indexMagasin >> prod.enSAV >> prod.factures >> prod.garanties;

    return in;
}

ProduitItem::ProduitItem(QWidget *parent, QString nomProduit, QDate dateAchat, QDate dateFinGarantie, QPixmap image, int magasin,
                         bool enSAV, QHash<QString, QByteArray> factures, QHash<QString, QByteArray> garanties) :
    QWidget(parent),
    ui(new Ui::ProduitItem)
{
    ui->setupUi(this);

    this->nomProduit = nomProduit;
    this->dateAchat = dateAchat;
    this->dateFinGarantie = dateFinGarantie;
    this->indexMagasin = magasin;
    this->enSAV = enSAV;
    this->factures = factures;
    this->garanties = garanties;

    ui->nomProduit->setText("<h1>"+nomProduit+"</h1>");
    updateDescription();
    this->image = image;
    this->image.scaled(QSize(128, 128), Qt::KeepAspectRatio);
    ui->image->setPixmap(this->image);
    ui->btnMoreInfo->setToolTip(tr("Ouvre une fenêtre contenant toutes les informations\nsur votre %1.", "%1 represents the name of the product, as given in the Name field.").arg(nomProduit));
}

void ProduitItem::on_btnMoreInfo_clicked(bool deleteOnCancel)
{
    InfosProduitDialog *winInfoProd = new InfosProduitDialog(this, this->parentWidget(), nomProduit, dateAchat, dateFinGarantie, image, indexMagasin, enSAV, factures, garanties);

    winInfoProd->setModal(true);
    winInfoProd->show();

    // Si on annule et que deleteOnCancel est vrai, le signal deleteAsked() sera déclenché.
    if(deleteOnCancel)
        connect(winInfoProd, SIGNAL(rejected()), SLOT(winInfoProdCanceled()));
}

void ProduitItem::winInfoProdCanceled()
{
    emit deleteAsked();
}

// Accesseurs
QPixmap ProduitItem::getImage()
{
    return this->image;
}

void ProduitItem::setNomProduit(QString nomProduit)
{
    this->nomProduit = nomProduit;
    ui->nomProduit->setText("<h1>"+nomProduit+"</h1>");
}

void ProduitItem::setDateAchat(QDate dateAchat)
{
    this->dateAchat = dateAchat;
    updateDescription();
}

void ProduitItem::setDateFinGarantie(QDate dateFinGarantie)
{
    this->dateFinGarantie = dateFinGarantie;
    updateDescription();
}

void ProduitItem::setImage(QPixmap image)
{
    this->image = image;
    ui->image->setPixmap(image);
}

int ProduitItem::getMagasin()
{
    return this->indexMagasin;
}

void ProduitItem::setMagasin(int index)
{
    this->indexMagasin = index;
}

void ProduitItem::setEnSAV(bool y)
{
    this->enSAV = y;
    updateDescription();
}

void ProduitItem::setFactures(QHash<QString, QByteArray> factures)
{
    this->factures = factures;
}

void ProduitItem::setGaranties(QHash<QString, QByteArray> garanties)
{
    this->garanties = garanties;
}

// Permet de mettre à jour le petit texte en-dessous du nom du produit
void ProduitItem::updateDescription()
{

    if(dateFinGarantie != QDate(1970, 1, 1))
    {
        if(QDate::currentDate() < dateFinGarantie)
            descriptionListe = tr("Acheté le %1, fin de la garantie le %2", "%1 and %2 are dates").arg(dateAchat.toString(Qt::LocaleDate), dateFinGarantie.toString(Qt::LocaleDate));
        else
            descriptionListe = tr("Acheté le %1, garantie expirée", "%1 is a date").arg(dateAchat.toString(Qt::LocaleDate));
    }
    else
        descriptionListe = tr("Acheté le %1, garantie à vie", "%1 is a date").arg(dateAchat.toString(Qt::LocaleDate));

    if(this->enSAV)
        descriptionListe += tr("\nParti en SAV");

    ui->infosProduit->setText(descriptionListe);
}

void ProduitItem::openDialog(bool deleteOnCancel)
{
    on_btnMoreInfo_clicked(deleteOnCancel);
}

// Pour la sérialisation

ProduitInfo ProduitItem::getProduitInfo()
{
    ProduitInfo i;
    i.nomProduit = this->nomProduit;
    i.dateAchat = this->dateAchat;
    i.dateFinGarantie = this->dateFinGarantie;
    i.image = this->image;
    i.indexMagasin = this->indexMagasin;
    i.enSAV = this->enSAV;
    i.factures = this->factures;
    i.garanties = this->garanties;

    return i;
}

QJsonObject ProduitItem::getJSON()
{
    // Convert image to base64
    QByteArray imageByteArray;
    QBuffer buffer(&imageByteArray);
    buffer.open(QIODevice::WriteOnly);
    this->image.toImage().save(&buffer, "JPEG");
    QString imageBase64 = imageByteArray.toBase64();

    // Fetch the shop's name
    ManufacturersManager manufacturersManager;
    QList<QString> manufacturers = manufacturersManager.getManufacturers();
    QString shopName = manufacturers[this->indexMagasin];

    // Attached documents
    QJsonObject jsonAttachedDocuments;
    for(int i = 0; i < factures.keys().length(); i++)
    {
        QString key = factures.keys()[i];
        QByteArray facture = factures[key];
        jsonAttachedDocuments["fac-" + key] = (QString) facture.toBase64();
    }

    for(int i = 0; i < garanties.keys().length(); i++)
    {
        QString key = garanties.keys()[i];
        QByteArray garantie = garanties[key];
        jsonAttachedDocuments["warr-" + key] = (QString) garantie.toBase64();
    }

    QJsonObject jsonObject;
    jsonObject["name"] = this->nomProduit;
    jsonObject["boughtOn"] = (int) ((QDateTime) this->dateAchat).toTime_t();
    jsonObject["warrantyEnd"] = (int) ((QDateTime) this->dateFinGarantie).toTime_t();
    jsonObject["image"] = imageBase64;
    jsonObject["shop"] = shopName;
    jsonObject["returnedToManufacturer"] = this->enSAV;
    jsonObject["attachedDocuments"] = jsonAttachedDocuments;

    return jsonObject;
}

ProduitItem::~ProduitItem()
{
    delete ui;
}
