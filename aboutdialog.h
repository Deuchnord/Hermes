#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent, QString version);
    ~AboutDialog();

private slots:
    void on_btnQt_clicked();

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
