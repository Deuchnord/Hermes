#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QMessageBox>

AboutDialog::AboutDialog(QWidget *parent, QString version) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->version->setText(tr("Version ")+version);
    ui->btnFermer->setFocus();
}

void AboutDialog::on_btnQt_clicked()
{
    QMessageBox::aboutQt(this, tr("À propos de Qt"));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}


