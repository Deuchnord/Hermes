#include "scannerdialog.h"
#include "ui_scannerdialog.h"

#include <QDir>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QMessageBox>
#include <iostream>

#ifdef Q_OS_WIN32
// Includes propre à Windows pour l'utilisation du scanner (via le service Windows Image Acquisition)
#include <windows.h>
#include <wia.h>
#include <wiadef.h>
#include <wiadevd.h>
#include <wiavideo.h>
#endif

ScannerDialog::ScannerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScannerDialog)
{
    ui->setupUi(this);
    ui->progressBar->hide();
}

ScannerDialog::~ScannerDialog()
{
    delete ui;
}

void ScannerDialog::on_btnTest_clicked()
{
#if defined Q_OS_LINUX
    ui->btnTest->setEnabled(false);
    ui->btnScan->setEnabled(false);
    ui->btnAnnuler->setEnabled(false);

    QProcess* process = new QProcess();
    process->setStandardOutputFile(QDir::tempPath() + "/test.pnm");
    process->start("scanimage");

    ui->progressBar->show();

    connect(process, SIGNAL(finished(int)), SLOT(scanTestFinished(int)));
#endif
}

void ScannerDialog::scanTestFinished(int r = 0)
{
#if defined Q_OS_WIN32
    QMessageBox::information(this, "test", "ok");
#elif defined Q_OS_LINUX
    ui->progressBar->hide();

    ui->btnTest->setEnabled(true);
    ui->btnScan->setEnabled(true);
    ui->btnAnnuler->setEnabled(true);

    std::string s = "convert " + QDir::tempPath().toStdString() + "/test.pnm " + QDir::tempPath().toStdString() + "/test.pdf";
    if(r == 0)
    {
        int c = system(s.c_str());
        if(c == 0)
            QDesktopServices::openUrl(QUrl("file://"+QDir::tempPath()+"/test.pdf"));
        else
            QMessageBox::critical(this, tr("Erreur"), tr("Votre document a pu être numérisé, mais un problème est survenu lors de son traitement.\nErreur %1").arg(QString::number(c)));
    }
    else
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de communiquer avec votre scanner. Vérifiez qu'il est bien relié à l'ordinateur' et qu'il est sous tension, puis réessayez.\nSi le problème persiste, il est probable que votre scanner ne soit pas pris en charge."));
#endif
}

void ScannerDialog::on_btnScan_clicked()
{
#ifdef Q_OS_LINUX
    ui->btnTest->setEnabled(false);
    ui->btnScan->setEnabled(false);
    ui->btnAnnuler->setEnabled(false);

    QProcess* process = new QProcess();
    process->setStandardOutputFile(QDir::tempPath() + "/output.pnm");
    process->start("scanimage --resolution 200");

    ui->progressBar->show();

    connect(process, SIGNAL(finished(int)), SLOT(scanFinished(int)));
#endif
}

void ScannerDialog::scanFinished(int r)
{
    ui->progressBar->hide();
    std::string s = "convert " + QDir::tempPath().toStdString() + "/output.pnm " + QDir::tempPath().toStdString() + "/output.pdf";
    if(r == 0)
    {
        int c = system(s.c_str());
        if(c != 0)
            QMessageBox::critical(this, tr("Erreur"), tr("Votre document a pu être numérisé, mais un problème est survenu lors de son traitement.\nErreur %1").arg(QString::number(c)));
        else
            this->accept();
    }
    else
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de communiquer avec votre scanner. Vérifiez qu'il est bien relié à l'ordinateur' et qu'il est sous tension, puis réessayez.\nSi le problème persiste, il est probable que votre scanner ne soit pas pris en charge."));
}
