#include "manufacturersmanager.h"

#include <QSettings>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>

/**
  * Class constructor
  */
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

/**
  * Adds a manufacturer to the list.
  * /!\ after adding a manufacturer, the <code>save</code> method should be called.
  * @param manufacturer the manufacturer to add
  */
void ManufacturersManager::addManufacturer(QString manufacturer) {

    manufacturers.append(manufacturer);
#define shouldsave 1

}

/**
  * @return a list of known manufacturers, including those that've been added with <code>addManufacturer()</code>.
  */
QList<QString> ManufacturersManager::getManufacturers() {

    return manufacturers;

}

/**
  * Deletes the manufacturer set in parameter.
  * /!\ after deleting a manufacturer, the <code>save</code> method should be called.
  * @param manufacturerToDelete the index of the manufacturer to delete
  */
void ManufacturersManager::deleteManufacturer(int manufacturerToDelete) {

    manufacturers.removeAt(manufacturerToDelete);
#define shouldsave 1

}

/**
  * Saves the changes made on the list of manufacturers.
  */
void ManufacturersManager::save() {

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

#undef shouldsave

}

ManufacturerManager::~ManufacturerManager() {

#ifdef shouldsave
#warning The manufacturers list have been changed, but has not been saved. You should call the save() method.
#endif

}
