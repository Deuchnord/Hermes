#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QList>
#include <QNetworkReply>

#include "produititem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow *getUI();
    ~MainWindow();

public slots:
    void dlVersionFinished(QNetworkReply* reply);
    void dlNewVersionBtnClicked();

    void searchProduit(QString search);
    void on_actionNouveauProduit_triggered();
    void on_actionSupprimerProduit_triggered(bool dontAskConfirm = true);
    void on_actionGererMagasins_triggered();
    void on_actionAPropos_triggered();
    void on_actionAide_triggered();
    void on_actionReportBug_triggered();

    void updateStatusMessage();

    void deleteAsked();

private:
    Ui::MainWindow *ui;
    QListWidgetItem *ajouterProduit(ProduitItem *produit);
    QLineEdit *searchBox;
    QString version;
};

#endif // MAINWINDOW_H
