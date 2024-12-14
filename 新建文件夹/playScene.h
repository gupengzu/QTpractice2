#pragma once
#include"dataconfig.h"
#include <QWidget>
#include <vector>
#include "MyCoin.h"
using namespace std;
class playScene  : public QWidget
{
	Q_OBJECT

public:
	playScene(int levelNumber);
	//翻转动画

	~playScene();
	//二维数组存储每关地16个硬币的数据
	vector<MyCoin*> coins;

signals:
	void playSceneBack(); // 自定义信号
};
