#ifndef FANJINBI_H
#define FANJINBI_H

#include <QMainWindow>
#include"chooselevelscene.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class fanjinbi;
}
QT_END_NAMESPACE

class fanjinbi : public QMainWindow
{
    Q_OBJECT

public:
    fanjinbi(QWidget *parent = nullptr);
    ~fanjinbi();


    //重写paintEvent事件 画背景图
    void paintEvent(QPaintEvent *event);

    ChooseLevelScene*chooseScene=NULL;
private:
    Ui::fanjinbi *ui;
};
#endif // FANJINBI_H
