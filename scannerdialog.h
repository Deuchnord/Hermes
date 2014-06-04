#ifndef SCANNERDIALOG_H
#define SCANNERDIALOG_H

#include <QDialog>

namespace Ui {
class ScannerDialog;
}

class ScannerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScannerDialog(QWidget *parent = 0);
    ~ScannerDialog();

private slots:
    void on_btnTest_clicked();
    void scanTestFinished(int r);
    void on_btnScan_clicked();
    void scanFinished(int r);

private:
    Ui::ScannerDialog *ui;
};

#endif // SCANNERDIALOG_H
