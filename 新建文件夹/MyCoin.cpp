#include "MyCoin.h"
#include <QPixmap>
#include <QDebug>

MyCoin::MyCoin(int x, int y, bool f)
    :posX(x), posY(y), flag(f), min(1), max(8) // 初始化 min 和 max
{
    this->setFixedSize(50, 50);
    this->setStyleSheet("QPushButton{border:0px;}");

    QPixmap pix;
    if (flag)
    {
        pix.load(":/res/Coin0001.png");
    }
    else
    {
        pix.load(":/res/Coin0008.png");
    }
    this->setIcon(QIcon(pix));
    this->setIconSize(QSize(50, 50));
    this->move(posX, posY);

    timer1 = new QTimer(this);
    connect(timer1, &QTimer::timeout, [=]()
    {
        if (flag)
        {
            QString str = QString(":/res/Coin000%1.png").arg(min++);
            QPixmap pix;
            pix.load(str);
            this->setFixedSize(pix.width(), pix.height());
            this->setIcon(QIcon(pix));
            this->setIconSize(QSize(50, 50));

            if (min > max)
            {
                min = 1;
                timer1->stop();
                flag = !flag;
				emit flipFinished();
            }
        }
        else
        {
            QString str = QString(":/res/Coin000%1.png").arg(max--);
            QPixmap pix;
            pix.load(str);
            this->setFixedSize(pix.width(), pix.height());
            this->setIcon(QIcon(pix));
            this->setIconSize(QSize(50, 50));

            if (max < min)
            {
                max = 8;
                timer1->stop();
                flag = !flag;
				emit flipFinished();
            }
        }
    });
}



void MyCoin::changeIcon()
{
    qDebug() << "Changing icon, flag is: " << flag;
    timer1->start(30);
}

MyCoin::~MyCoin()
{
}
