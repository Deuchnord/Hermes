#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QList>

#include "produititem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void searchProduit(QString search);
    void on_actionNouveauProduit_triggered();
    void on_actionSupprimerProduit_triggered();
    void on_actionGererMagasins_triggered();
    void on_listeProduits_currentRowChanged();
    void on_actionAPropos_triggered();
    void on_actionAide_triggered();

private:
    Ui::MainWindow *ui;
    void ajouterProduit(ProduitItem *produit);
    QLineEdit *searchBox;
    QString version;
};

#endif // MAINWINDOW_H
