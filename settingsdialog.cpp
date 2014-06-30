#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    settings = new QSettings("Deuchnord", "Hermes");
    savePlace = settings->value("placeSave").toString();

    ui->currentPlaceSave->setText(savePlace);
}

void SettingsDialog::on_btnChangeSavePlace_clicked()
{
    QString savePlace = QFileDialog::getExistingDirectory(this, tr("Choisir un dossier de sauvegarde"), settings->value("placeSave").toString());
    bool ok = true;
    bool replaceFile = false;
    QDir dir(savePlace+"/deuchnord-hermes");
    if(dir.exists())
    {
        int whatToDo = QMessageBox::question(this, tr("Confirmation"), tr("Des fichiers appartenant à Hermès semblent être déjà présents. Que voulez-vous faire ?<br />Cliquez sur <em>Appliquer</em> pour utiliser les fichiers présents à cet emplacement.<br />Cliquez sur <em>Réinitialiser</em> pour écraser les fichiers présents à cet emplacement.<br />Cliquez sur <em>Annuler</em> pour ne pas changer l'emplacement.", "The texts in italic should correspond to the texts on the buttons."), QMessageBox::Apply | QMessageBox::Reset | QMessageBox::Cancel, QMessageBox::Cancel);

        switch(whatToDo)
        {
        case QMessageBox::Reset:
            replaceFile = true;
            break;
        case QMessageBox::Cancel:
            ok = false;
            break;
        }
    }
    else
        replaceFile = true;

    if(ok)
    {
        ui->currentPlaceSave->setText(savePlace);
        this->savePlace = savePlace;
        this->replaceFile = replaceFile;
    }
}

void SettingsDialog::on_buttonBox_accepted()
{
    bool restartNeeded = false, restartWillSave = true;

    // Emplacement de la sauvegarde
    if(savePlace != settings->value("placeSave").toString())
    {
        if(!replaceFile)
        {
            restartNeeded = true;
            restartWillSave = false;
            emit dontSaveOnQuit();
        }

        else
        {
            QDir dir(savePlace+"/deuchnord-hermes");
            dir.mkdir(savePlace+"/deuchnord-hermes");
            QFile::copy(settings->value("placeSave").toString()+"/deuchnord-hermes/manufacturers.xml", savePlace+"/deuchnord-hermes/manufacturers.xml");
        }

        settings->setValue("placeSave", savePlace);
    }

    // Affichage d'un message s'il faut redémarrer Hermès
    if(restartNeeded)
    {
        QString message = tr("Certains changements dans votre configuration nécessitent de relancer Hermès.");
        if(!restartWillSave)
            message += tr("\nAttention, les changements effectués ne seront pas enregistrés !");
        QMessageBox::warning(this, tr("Mise à jour de la configuration"), message);
    }
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}
