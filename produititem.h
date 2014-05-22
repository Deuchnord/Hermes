#ifndef PRODUITITEM_H
#define PRODUITITEM_H

#include <QWidget>
#include <QPixmap>
#include <QDate>
#include <QByteArray>
#include <QHash>
#include <QDataStream>

#include "infosproduitdialog.h"

namespace Ui {
class ProduitItem;
}

struct ProduitInfo {
    QString nomProduit;
    QDate dateAchat, dateFinGarantie;
    QPixmap image;
    qint32 indexMagasin;
    bool enSAV;
    QHash<QString, QByteArray> factures, garanties;
};

QDataStream &operator <<(QDataStream &out, const ProduitInfo &prod);
QDataStream &operator >>(QDataStream &in, ProduitInfo &prod);


class ProduitItem : public QWidget
{
    Q_OBJECT

public:
    explicit ProduitItem(QString nomProduit, QDate dateAchat, QDate dateFinGarantie, QPixmap image = QPixmap(":/images/no-picture.jpg"), int magasin = 0,
                         bool enSAV = false, QHash<QString, QByteArray> factures = QHash<QString, QByteArray>(), QHash<QString, QByteArray> garanties = QHash<QString, QByteArray>());
    explicit ProduitItem(ProduitInfo prod);
    explicit ProduitItem();

    /*QVector<ProduitItem*> items;

    ProduitInfo info();
    QVector<ProduitItem> extractInfo(QVector<ProduitItem*> const& v);
    static void save(QDataStream & out, QVector<ProduitInfo> const& v);
    ProduitItem* create(ProduitInfo const& info);
    QVector<ProduitItem*> load(QDataStream & in);*/

    // Pour la sérialisation
    ProduitInfo getProduitInfo();

    // Getters
    QPixmap getImage();

    // Setters
    void setNomProduit(QString nomProduit);
    void setDateAchat(QDate dateAchat);
    void setDateFinGarantie(QDate dateFinGarantie);
    void setImage(QPixmap image);
    void setMagasin(int index); // le QString ne sert qu'à l'affichage, c'est l'index qui est utilisé par la boîte de dialogue
    void setEnSAV(bool y);
    void setFactures(QHash<QString, QByteArray> factures);
    void setGaranties(QHash<QString, QByteArray> garanties);

    void updateDescription();
    void openDialog();

    // Destructeur
    ~ProduitItem();

public slots:
    void on_btnMoreInfo_clicked();

private:
    Ui::ProduitItem *ui;

    QString nomProduit;
    QDate dateAchat, dateFinGarantie;
    QString descriptionListe;
    QPixmap image;
    int indexMagasin;
    bool enSAV;
    QHash<QString, QByteArray> factures;
    QHash<QString, QByteArray> garanties;
};

#endif // PRODUITITEM_H
