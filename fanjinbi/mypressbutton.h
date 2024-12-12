#ifndef MYPRESSBUTTON_H
#define MYPRESSBUTTON_H
#include<QPushButton>
class MyPressButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPressButton(QWidget *parent = nullptr);
    //构造函数      参数1 正常显示的图片路径  参数2 按下后显示的图片路径
    MyPressButton(QString normalImg,QString pressImg="");

    //成员属性 保存用户传入的默认显示路径 以及按下后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;
    //弹跳特效
    void zoom1();

    void zoom2();

    void mousePressEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent*e);

signals:
};

#endif // MYPRESSBUTTON_H
