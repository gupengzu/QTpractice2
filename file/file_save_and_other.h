#ifndef FILE_SAVE_AND_OTHER_H
#define FILE_SAVE_AND_OTHER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class file_save_and_other;
}
QT_END_NAMESPACE

class file_save_and_other : public QMainWindow
{
    Q_OBJECT

public:
    file_save_and_other(QWidget *parent = nullptr);
    ~file_save_and_other();

private:
    Ui::file_save_and_other *ui;
};
#endif // FILE_SAVE_AND_OTHER_H
