#ifndef MANUFACTURERSMANAGER_H
#define MANUFACTURERSMANAGER_H

#include <QList>

class ManufacturersManager
{

public:
    explicit ManufacturersManager();
    void addManufacturer(QString manufacturer);
    QList<QString> getManufacturers();
    void deleteManufacturer(int manufacturerToDelete);
    void save();

private:
    QList<QString> manufacturers;

};

#endif // MANUFACTURERSMANAGER_H
