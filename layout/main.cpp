#include "_Layout.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _Layout w;
    w.show();
    return a.exec();
}
