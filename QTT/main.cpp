#include "_QtSource.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _QtSource w;
    w.show();
    return a.exec();
}
