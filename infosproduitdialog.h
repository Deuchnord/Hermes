#ifndef INFOSPRODUITDIALOG_H
#define INFOSPRODUITDIALOG_H

#include <QDialog>
#include <QDate>
#include <QHash>
#include <QListWidget>
#include <QPixmap>
#include "produititem.h"

namespace Ui {
class InfosProduitDialog;
}

class ProduitItem;

class InfosProduitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfosProduitDialog(QWidget *parent, QString nomProduit = "", QDate dateAchat = QDate::currentDate(), QDate dateFinGarantie = QDate::currentDate().addYears(1), QPixmap image = QPixmap(), int indexMagasin = 0, bool enSAV = false, QHash<QString, QByteArray> facturePDF = QHash<QString, QByteArray>(), QHash<QString, QByteArray> garantiePDF = QHash<QString, QByteArray>());
    ~InfosProduitDialog();

public slots:
    // Image
    void on_btnImageParcourir_clicked();
    void on_btnImageSupprimer_clicked();
    // Factures
    void on_btnAjoutFacture_clicked();
    void on_listFactures_currentRowChanged();
    void on_listFactures_itemDoubleClicked(QListWidgetItem *item);
    void on_btnSupprFacture_clicked();
    // Garanties
    void on_btnAjoutGarantie_clicked();
    void on_listGaranties_currentRowChanged();
    void on_listGaranties_itemDoubleClicked(QListWidgetItem *item);
    void on_btnSupprGarantie_clicked();
    // Boutons du bas
    void on_buttonBox_accepted();

private:
    QPixmap image;
    Ui::InfosProduitDialog *ui;
    QHash<QString, QByteArray> facturePDF;
    QHash<QString, QByteArray> garantiePDF;
    QWidget *parentWidget;
    ProduitItem *getParentItem();
};

#endif // INFOSPRODUITDIALOG_H
