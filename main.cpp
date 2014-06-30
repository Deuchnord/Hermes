#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);

    QTranslator* translator = new QTranslator();
    translator->load("translations/"+locale+".qm");
    a.installTranslator(translator);

    MainWindow w;
    w.show();

    return a.exec();
}
