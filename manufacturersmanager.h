#ifndef MANUFACTURERSMANAGER_H
#define MANUFACTURERSMANAGER_H

#include <QList>

class ManufacturersManager
{

public:
    ManufacturersManager();
    void addManufacturer(QString manufacturer);
    QList<QString> getManufacturers();
    void deleteManufacturer(int manufacturerToDelete);
    void save();
    ~ManufacturersManager();

private:
    QList<QString> manufacturers;

};

#endif // MANUFACTURERSMANAGER_H
