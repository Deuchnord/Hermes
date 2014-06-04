#ifndef GESTIONMAGASINSDIALOG_H
#define GESTIONMAGASINSDIALOG_H

#include <QDialog>

namespace Ui {
class GestionMagasinsDialog;
}

class GestionMagasinsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GestionMagasinsDialog(QWidget *parent = 0);
    ~GestionMagasinsDialog();

public slots:
    void on_btnAjoutMagasin_clicked();
    void on_btnSupprMagasin_clicked();
    void on_listMagasins_currentRowChanged();
    void on_buttonBox_accepted();

signals:
    void magasinDeleted(int indexMagasin);

private:
    Ui::GestionMagasinsDialog *ui;
};

#endif // GESTIONMAGASINSDIALOG_H
