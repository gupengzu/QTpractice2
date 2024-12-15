#include "_QDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _QDialog w;
    w.show();
    return a.exec();
}
