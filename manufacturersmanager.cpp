#include "manufacturersmanager.h"

#include <QSettings>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>

ManufacturersManager::ManufacturersManager()
{
    QSettings *settings = new QSettings("Deuchnord", "Hermes");
    QFile fichierMagasins(settings->value("placeSave").toString()+"/deuchnord-hermes/manufacturers.xml");
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
                manufacturers.append(manufacturer.firstChild().toText().data());

            node = node.nextSibling();
        }
    }
}

void ManufacturersManager::addManufacturer(QString manufacturer) {

    manufacturers.append(manufacturer);

}

QList<QString> ManufacturersManager::getManufacturers() {

    return manufacturers;

}

void ManufacturersManager::deleteManufacturer(int manufacturerToDelete) {

    manufacturers.removeAt(manufacturerToDelete);

}

ManufacturersManager::save() {

    QDomDocument dom("manufacturers");
    QDomElement rootElement = dom.createElement("manufacturers");
    dom.appendChild(rootElement);

    for(QString manufacturer : manufacturers) {

        QDomElement domManufacturer = dom.createElement("manufacturer");
        root.appendChild(domManufacturer);
        QDomText textManufacturer = dom.createTextNode(manufacturer);
        domManufacturer.appendChild(textManufacturer);

    }

    QSettings *settings = new QSettings("Deuchnord", "Hermes");
    QFile fichierMagasins(settings->value("placeSave").toString()+"/deuchnord-hermes/manufacturers.xml");

    if(fichierMagasins.open(QFile::WriteOnly)) {

        fichierMagasins.write(dom.toString().toUtf8());
        fichierMagasins.close();

    }

}
