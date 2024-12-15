#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class paint;
}
QT_END_NAMESPACE

class paint : public QMainWindow
{
    Q_OBJECT

public:
    paint(QWidget *parent = nullptr);
    ~paint();

    void paintEvent(QPaintEvent *event);

    int x=0;

private:
    Ui::paint *ui;
};
#endif // PAINT_H
