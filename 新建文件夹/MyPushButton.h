#pragma once

#include <QPushButton>
#include<qstring.h>
#include<ChooseScene.h>
class MyPushButton  : public QPushButton
{
	Q_OBJECT

public:

	MyPushButton(QString normalImg,QString specialImg="");
	//弹起动画
	void zoom1();
	void zoom2();


	QString normalImgPath;
	QString specialImgPath;

	~MyPushButton();
};
