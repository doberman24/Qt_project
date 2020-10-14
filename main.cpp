#include "build.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Build w;
    w.show();
    w.resize(400, 690);
    w.move(400, 0);

    return a.exec();
}
