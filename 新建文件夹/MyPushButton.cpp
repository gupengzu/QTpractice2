#include "MyPushButton.h"
#include<qdebug.h>
#include<qpixmap.h>
#include<qpropertyanimation.h>
MyPushButton::MyPushButton(QString normalImg, QString specialImg)
	:normalImgPath(normalImg),specialImgPath(specialImg)
{
	QPixmap pix;
	bool res = pix.load(normalImg);
	if (!res)
	{
		qDebug() << "图片加载失败";
		return;
	}

	//固定图片大小
	this->setFixedSize(pix.width(),pix.height());
	//设置不规则图片
	this->setStyleSheet("QPushButton{border:Opx}");
	//设置图标
	this->setIcon(pix);
	//设置图标大小	
	this->setIconSize(QSize(pix.width(), pix.height()));


}

void MyPushButton::zoom1()
{
	//创建动画
	QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
	//设置时间间隔
	animation->setDuration(200);
	//设置动画曲线
	animation->setEasingCurve(QEasingCurve::OutBounce);
	//设置起始位置
	animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
	//设置结束位置
	animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
	//执行动画
	animation->start();
}

void MyPushButton::zoom2()
{
	//创建动画
	QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
	//设置时间间隔
	animation->setDuration(200);
	//设置动画曲线
	animation->setEasingCurve(QEasingCurve::OutBounce);
	//设置起始位置
	animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
	//设置结束位置
	animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
	//执行动画
	animation->start();
}




MyPushButton::~MyPushButton()
{

}
