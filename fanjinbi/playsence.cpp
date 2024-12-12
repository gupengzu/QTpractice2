#include "playsence.h"
#include<QDebug>
#include<QMenuBar>
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include<QLabel>
#include<mycoin.h>
#include"dataconfig.h"
#include<QPropertyAnimation>
#include<QSoundEffect>
#include<QUrl>
// PlaySence::PlaySence(QWidget *parent)
//     : QMainWindow{parent}
// {}

PlaySence::PlaySence(int levelNum)
{
    QString str=QString("进入了第%1关").arg(levelNum);
    qDebug()<<str;
    this->levelIndex=levelNum;

    //初始化游戏场景
    //设置固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/111/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("快乐翻金币");
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


    //添加音效资源
    //返回
    QSoundEffect* back2Sound = new QSoundEffect(this);
    back2Sound->setSource(QUrl::fromLocalFile(":/111/res/BackButtonSound.wav"));
    //翻金币
    QSoundEffect* fanSound = new QSoundEffect(this);
    fanSound->setSource(QUrl::fromLocalFile(":/111/res/ConFlipSound.wav"));
    QSoundEffect* winSound = new QSoundEffect(this);
    winSound->setSource(QUrl::fromLocalFile(":/111/res/LevelWinSound.wav"));


    //返回按钮
    MyPressButton*backBtn=new MyPressButton(":/111/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击返回
    connect(backBtn,&MyPressButton::clicked,[=](){
        qDebug()<<"返回选关界面";
        back2Sound->play();
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();
        });
    });



    //显示当前关卡数(左下角)
    QLabel*label=new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("微软雅黑");
    font.setPointSize(20);
    QString str1=QString("LEVEL:%1").arg(this->levelIndex);
    //将字体设置到标签中
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(30,this->height()-50,120,50);//设置一个矩形框来确定label的大小与位置

    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j]=config.mData[this->levelIndex][i][j];

        }
    }

    //胜利图片显示
    QLabel*winLabel=new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/111/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move(this->width()*0.5-tmpPix.width()*0.5,-tmpPix.height());


    //显示金币的背景图片
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            //绘制图片
            QPixmap pix=QPixmap(":/111/res/BoardNode(1).png");
            QLabel*label1=new QLabel;
            label1->setGeometry(0,0,50,50);
            label1->setPixmap(pix);
            label1->setParent(this);
            label1->move(57+i*50,200+j*50);
            //创建金币

            QString str2;
            if(this->gameArray[i][j]==1)
            {
                //显示金币
                str2=":/111/res/Coin0001.png";

            }
            else
            {
                str2=":/111/res/Coin0008.png";
            }
            MyCoin*coin=new MyCoin(str2);
            coin->setParent(this);
            coin->move(57+i*50,200+j*50);

            //给金币属性赋值
            coin->posX=i;
            coin->posY=j;
            coin->flag=this->gameArray[i][j];//1正面 2反面

            //将金币放入到 金币的二维数组里 以便以后期的维护
            coinBtn[i][j]=coin;


            //点击金币 进行翻转
            connect(coin,&MyCoin::clicked,[=](){
                fanSound->play();
                //点击按钮，将所有按钮都禁用
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        this->coinBtn[i][j]->isWin=true;
                    }
                }


                coin->changeFlag();
                this->gameArray[i][j]=this->gameArray[i][j]==0?1:0;
                //延时翻转
                QTimer::singleShot(300,this,[=](){


                    //翻转周围金币
                    //翻转左侧硬币
                    if(coin->posX+1<=3)
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY]=this->gameArray[coin->posX+1][coin->posY]==0?1:0;
                    }
                    //翻转右侧硬币
                    if(coin->posX-1>=0)
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY]=this->gameArray[coin->posX-1][coin->posY]==0?1:0;
                    }
                    //翻转下侧硬币
                    if(coin->posY+1<=4)
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1]=this->gameArray[coin->posX][coin->posY+1]==0?1:0;
                    }
                    //翻转上侧硬币
                    if(coin->posY-1>=0)
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1]=this->gameArray[coin->posX][coin->posY-1]==0?1:0;
                    }


                    //点击按钮，将所有按钮都启用
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            this->coinBtn[i][j]->isWin=false;
                        }
                    }


                    //判断是否胜利
                    this->isWin=true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            if(this->coinBtn[i][j]->flag==false)
                            {
                                isWin=false;
                            }
                        }
                    }
                    if(this->isWin)
                    {
                        winSound->play();
                        //胜利了
                        qDebug()<<"游戏胜利了";
                        //将所有按钮的胜利标志改为true
                        for(int i=0;i<4;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                                 coinBtn[i][j]->isWin=true;
                            }
                        }

                        //将胜利图片拿下来
                        QPropertyAnimation*animation=new QPropertyAnimation(winLabel,"geometry");
                        //设置时间间隔
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        //设置缓冲曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation->start();
                    }


                });
            });
        }
    }

}

void PlaySence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    //创建背景
    pix.load(":/111/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/111/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);

}





