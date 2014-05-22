#include "gestionmagasinsdialog.h"
#include "ui_gestionmagasinsdialog.h"

#include <QDir>
#include <QFile>
#include <QtXml>
#include <QInputDialog>

GestionMagasinsDialog::GestionMagasinsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionMagasinsDialog)
{
    ui->setupUi(this);

    QFile fichierMagasins(QDir::homePath()+"/.deuchnord-hermes/manufacturers.xml");
    fichierMagasins.open(QFile::ReadOnly);
    if(fichierMagasins.isOpen())
    {
        QString contenuFichier = fichierMagasins.readAll();
        fichierMagasins.close();

        QDomDocument dom;
        dom.setContent(contenuFichier);
        QDomElement root = dom.firstChildElement();
        QDomElement manufacturer;
        QDomNode node = root.firstChild();

        while(!node.isNull())
        {
            manufacturer = node.toElement();
            if(manufacturer.tagName() == "manufacturer")
                ui->listMagasins->addItem(manufacturer.firstChild().toText().data());

            node = node.nextSibling();
        }

        fichierMagasins.close();
    }

    ui->listMagasins->setCurrentItem(ui->listMagasins->item(0));
}

void GestionMagasinsDialog::on_btnAjoutMagasin_clicked()
{
    ui->listMagasins->addItem(QInputDialog::getText(this, "Ajouter un magasin", "Veuillez entrer le nom du nouveau magasin :"));
}

void GestionMagasinsDialog::on_btnSupprMagasin_clicked()
{
    delete ui->listMagasins->currentItem();
}

void GestionMagasinsDialog::on_listMagasins_currentRowChanged()
{
    ui->btnSupprMagasin->setEnabled(true);
}

void GestionMagasinsDialog::on_buttonBox_accepted()
{
    QDomDocument dom("manufacturers");
    QDomElement rootElement = dom.createElement("manufacturers");
    dom.appendChild(rootElement);

    for(int i = 0; i < ui->listMagasins->count(); i++)
    {
        QDomElement manufacturer = dom.createElement("manufacturer");
        rootElement.appendChild(manufacturer);

        QListWidgetItem *item = ui->listMagasins->item(i);

        QDomText nomMagasin = dom.createTextNode(item->text());
        manufacturer.appendChild(nomMagasin);
    }

    QFile fileManu(QDir::homePath()+"/.deuchnord-hermes/manufacturers.xml");
    if(fileManu.open(QFile::WriteOnly))
    {
        fileManu.write(dom.toString().toUtf8());
        fileManu.close();
    }
}

GestionMagasinsDialog::~GestionMagasinsDialog()
{
    delete ui;
}
