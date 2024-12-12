#include "fanjinbi.h"
#include "ui_fanjinbi.h"
#include<QPainter>
#include"mypressbutton.h"
#include<QDebug>
#include<QTimer>
#include<QSoundEffect>
#include <QUrl>
#include<chooselevelscene.h>
fanjinbi::fanjinbi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fanjinbi)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/111/res/Coin0001.png"));

    //设置标题
    setWindowTitle("反转金币主场景");

    //退出按钮的实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });
    //准备开始按钮的音效
    QSoundEffect* startSound = new QSoundEffect(this);
    startSound->setSource(QUrl::fromLocalFile(":/111/res/TapButtonSound.wav"));
    //startSound->setLoopCount(-1);//设置（-1代表无限）循环



    //开始按钮的实现
    MyPressButton*startButton=new MyPressButton(":/111/res/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(this->width()*0.5-startButton->width()*0.5,this->height()*0.7);

    //实例化选择关卡的场景
    chooseScene=new ChooseLevelScene;


    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        QTimer::singleShot(500,this,[=](){
            this->setGeometry(chooseScene->geometry());
            chooseScene->hide();
            this->show();
        });

    });


    connect(startButton,&MyPressButton::clicked,[=]()
    {
        //qDebug()<<"点击";
        //播放开始音效资源
        startSound->play();

        //作弹跳特效
        startButton->zoom1();
        startButton->zoom2();


    //为保证显示完弹跳特效后再跳转，在这里有一个延时效果
    QTimer::singleShot(500,this,[=]()
        {
        //设置chooseScene场景的位置
        chooseScene->setGeometry(this->geometry());//让下一个场景在上一个场景的结束位置

        //进入到选择关卡的场景中
        //使得第一张图片隐藏
        this->hide();
        //显示选择关卡的场景
        chooseScene->show();
        });




    });


}

void fanjinbi::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/111/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画一个背景上的图标
    pix.load(":/111/res/Title.png");

    //缩放图片
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);


    painter.drawPixmap(0,0,pix);
}

fanjinbi::~fanjinbi()
{
    delete ui;
}
