#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

private slots:
    void on_btnChangeSavePlace_clicked();
    void on_buttonBox_accepted();

signals:
    void dontSaveOnQuit(); // Signal indiquant à la fenêtre principale de ne pas enregistrer à la fermeture.

private:
    Ui::SettingsDialog *ui;
    QSettings *settings;
    QString savePlace;
    bool replaceFile;
};

#endif // SETTINGSDIALOG_H
