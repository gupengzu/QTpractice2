#include "paint.h"
#include "ui_paint.h"
#include<QPainter>
paint::paint(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::paint)
{
    ui->setupUi(this);

    //点击移动按钮
    connect(ui->pushButton,&QPushButton::clicked,[=]()
            {
        x+=20;
        update();

    });
}

paint::~paint()
{
    delete ui;
}
 void paint::paintEvent(QPaintEvent *event)
{
    //  QPainter painter(this);

    // QPen pen(QColor(255,0,0));
    //  pen.setWidth(2);
    // pen.setStyle(Qt::DotLine);
    //  painter.setPen(pen);

    // QBrush brush(Qt::cyan);
    //  painter.setBrush(brush);

    // painter.drawLine(QPoint(0,0),QPoint(100,200));
    //  painter.drawEllipse(QPoint(100,100),50,50);
    // painter.drawRect(QRect(20,20,50,50));
    //  painter.drawText(QRect(10,200,100 ,50),"好好学习");


    //QPainter painter(this);
    //  painter.drawEllipse(QPoint(200,200),30,30);
    // painter.setRenderHint(QPainter::Antialiasing);
    // painter.drawEllipse(QPoint(150,150),30,30);

    // painter.drawRect(QRect(20,20,50,50));
    // painter.translate(100,0);
    // painter.drawLine(QPoint(1,1),QPoint(2,5));
    // painter.save();
    // painter.translate(200,0);
    // painter.drawRect(QRect(20,20,50,50));
    // painter.restore();
    // painter.drawRect(QRect(20,20,500,70));

    QPainter painter(this);
    if(x>this->width())
    {
        x=0;
    }
    painter.translate(x,0);
    painter.drawPixmap(20,100,QPixmap(":/1/photos/bk.jpg"));
}
