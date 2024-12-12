#ifndef PLAYSENCE_H
#define PLAYSENCE_H

#include <QMainWindow>
#include<mypressbutton.h>
#include"mycoin.h"
class PlaySence : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlaySence(QWidget *parent = nullptr);
    PlaySence(int level);
    int levelIndex;//内部成员属性  记录所选的关卡

    //重写paintEvent事件
    void paintEvent(QPaintEvent*);


    //返回按钮
    MyPressButton*backBtn=NULL;

    //二维数组 维护每个关卡的具体数据
    int gameArray[4][4];

    //二维数组，用于维护在
    MyCoin*coinBtn[4][4];


    //是否胜利的标志
    bool isWin=true;

signals:
    void chooseSceneBack();//自定义信号可以一样，因为有作用区间“PlaySence：：”
};

#endif // PLAYSENCE_H
