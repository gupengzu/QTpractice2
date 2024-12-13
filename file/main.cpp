#include "file_save_and_other.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    file_save_and_other w;
    w.show();
    return a.exec();
}
