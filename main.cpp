#include "clientconnection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientConnection w;
    w.show();

    return a.exec();
}
