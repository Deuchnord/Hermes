#include "produititem.h"
#include "ui_produititem.h"

#include <QMessageBox>

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
    ui->btnMoreInfo->setToolTip("Ouvre une fenêtre contenant toutes les informations\nsur votre "+nomProduit+".");
}

void ProduitItem::on_btnMoreInfo_clicked()
{
    InfosProduitDialog *winInfoProd = new InfosProduitDialog(this->parentWidget(), nomProduit, dateAchat, dateFinGarantie, image, indexMagasin, enSAV, factures, garanties);
    winInfoProd->setModal(true);
    winInfoProd->show();
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
    QString jourAchat = QString::number(dateAchat.day());

    if(dateAchat.day() < 10)
        jourAchat = "0"+jourAchat;

    QString moisAchat = QString::number(dateAchat.month());

    if(dateAchat.month() < 10)
        moisAchat = "0"+moisAchat;

    descriptionListe = "Acheté le "+jourAchat+"/"+moisAchat+"/"+QString::number(dateAchat.year())+", ";

    QString jourFinGarantie = QString::number(dateFinGarantie.day());

    if(dateFinGarantie.day() < 10)
        jourFinGarantie = "0"+jourFinGarantie;

    QString moisFinGarantie = QString::number(dateFinGarantie.month());

    if(dateFinGarantie.month() < 10)
        moisFinGarantie = "0"+moisFinGarantie;

    if(QDate::currentDate() < dateFinGarantie)
        descriptionListe += "fin de la garantie le "+jourFinGarantie+"/"+moisFinGarantie+"/"+QString::number(dateFinGarantie.year());
    else
        descriptionListe += "garantie expirée";

    if(this->enSAV)
        descriptionListe += "\nParti en SAV";

    ui->infosProduit->setText(descriptionListe);
}

void ProduitItem::openDialog()
{
    ui->btnMoreInfo->click();
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

ProduitItem::~ProduitItem()
{
    delete ui;
}
