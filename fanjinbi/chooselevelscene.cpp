#include "chooselevelscene.h"
#include <QMenuBar>
#include<QPainter>
#include<QPixmap>
#include<mypressbutton.h>
#include<QDebug>
#include<QString>
#include<QLabel>
#include<QSoundEffect>
#include <QUrl>
ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{

    //配置选择关卡场景
    this->setFixedSize(320,588);

    //设置图标
    this->setWindowIcon(QPixmap(":/111/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单栏
    QMenuBar*bar=menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu* startMenu =bar->addMenu("开始");

    //创建退出 菜单项
    QAction*quitAction=startMenu->addAction("退出");

    //点击退出 实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });


    //选择关卡按钮音效
    QSoundEffect*chooseSound=new QSoundEffect();
    chooseSound->setSource(QUrl::fromLocalFile(":/111/res/TapButtonSound.wav"));
    //返回按钮音效
    QSoundEffect*backSound=new QSoundEffect();
    backSound->setSource(QUrl::fromLocalFile(":/111/res/BackButtonSound.wav"));

    //返回按钮
    MyPressButton* backBtn=new MyPressButton(":/111/res/BackButton.png",":/111/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    // backBtn->show();在fanjinbi中已经有show了

    //点击back能返回
    connect(backBtn,&MyPressButton::clicked,[=](){
        //qDebug()<<"返回";

        backSound->play();

        emit this->chooseSceneBack();
    });

    //创建选择关卡的按钮
    for(int i=0;i<20;i++)
    {
        MyPressButton* menuBtn=new MyPressButton(":/111/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,130+i/4*70);

        //监听每个按钮的点击事件
        connect(menuBtn,&MyPressButton::clicked,[=](){
            //播放选择关卡音效
            chooseSound->play();

            QString str=QString("选择的是第%1关").arg(i+1);
            qDebug()<<str;



            //进入到游戏场景
            this->hide();//将选关场景隐藏掉
            play=new PlaySence(i+1);
            //设置游戏场景的初始位置
            play->setGeometry(this->geometry());
            play->show();//显示游戏场景


            connect(play,&PlaySence::chooseSceneBack,[=](){
                this->setGeometry(this->geometry());
                this->show();
                delete play;
                play=NULL;
            });
        });




        //这个方法有问题，无法使number的数字落到指定位置
        //menuBtn->setText(QString::number(i+1));

        QLabel*label=new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+i%4*70,130+i/4*70);

        //设置label的对齐方式   水平居中            垂直居中
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //设置让鼠标进行穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}
   void ChooseLevelScene::paintEvent(QPaintEvent*)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/111/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/111/res/Title.png");

    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);

}







