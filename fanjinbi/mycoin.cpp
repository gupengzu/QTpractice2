#include "mycoin.h"
#include<QDebug>
// MyCoin::MyCoin(QWidget *parent)
//     : QWidget{parent}
// {}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret=pix.load(btnImg);
    if(!ret)
    {
        QString str=QString("图片%1加载失败").arg(btnImg);
        qDebug()<<str;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器
    timer1=new QTimer(this);
    timer2=new QTimer(this);
    //监听正面翻反面的信号，并且翻转金币
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/111/res/Coin000%1").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:Opx}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断 如果翻完了，将min重置为1
        if(this->min>this->max)
        {
            this->min=1;
            isAnimation=false;//做完动画了
            timer1->stop();
        }
    });

    //监听反面翻正面的信号，并且翻转银币
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/111/res/Coin000%1").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:Opx}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断 如果翻完了，将max重置为1
        if(this->max<this->min)
        {
            this->max=8;
            isAnimation=false;//作完动画了
            timer2->stop();
        }
    });
}
//改变正反面的方法
void MyCoin::changeFlag()
{
    //如是正面 翻成反面
    if(this->flag)
    {
        //开始正面翻面的定时器
        timer1->start(30);
        isAnimation=true;//开始作动画
        this->flag=false;

    }
    else
    {
        timer2->start(30);
        isAnimation=true;//开始做动画
        this->flag=true;
    }

}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation==true||this->isWin)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
