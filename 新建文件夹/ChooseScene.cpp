#include "ChooseScene.h"
#include <QMenuBar>
#include <MyPushButton.h>
#include <QDebug>
#include <QTimer>
#include<QLabel>
#include"dataconfig.h"

ChooseScene::ChooseScene(QWidget* parent)
    : QWidget(parent)
{
    qDebug() << "ChooseScene构造调用";
    //设置对话框固定大小
    this->setFixedSize(400, 588);
    //设置对话框标题
    this->setWindowTitle("Choose Scene");
    //设置对话框图标（左上角）
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置对话框背景
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/res/OtherSceneBg.png")));
    this->setPalette(palette);

    //设置菜单栏
    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* fileMenu = menuBar->addMenu("功能");
    QAction* exitAction = fileMenu->addAction("退出");
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
    menuBar->setGeometry(0, 0, this->width(), 30);

    //设置退出按钮
    MyPushButton* closeBtn = new MyPushButton(":/res/BackButton.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width() - closeBtn->width(), this->height() - closeBtn->height());

    //连接点击事件到返回信号
    connect(closeBtn, &MyPushButton::clicked, [=]() {
        //返回按钮特效
        closeBtn->zoom1();
        closeBtn->zoom2();
        //延时返回
        QTimer::singleShot(200, this, [=]() {
            //发射自定义信号，告诉主场景 我要返回了
            emit chooseSceneBack();
        });
    });



	//开始绘制选择关卡按钮
	for (int i = 0; i < 20; i++)
	{
		MyPushButton* levelBtn = new MyPushButton(":/res/LevelIcon.png");
		levelBtn->setParent(this);
		levelBtn->move(25 + i % 4 * 70, 130 + i / 4 * 70);
        //设置字体与大小
        QFont font;
        font.setFamily("微软雅黑");
		font.setPointSize(20);
		//设置按钮上的文字

		QLabel* label = new QLabel(this);
        label->setFont(font);
        label->setParent(this);
		label->setFixedSize(levelBtn->width(), levelBtn->height());
		//设置文字内容
		label->setText(QString::number(i + 1));
        //移动文字
		label->move(25 + i % 4 * 70, 130 + i / 4 * 70);
		//设置文字对齐方式
		label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        //设置按钮的鼠标穿透
		label->setAttribute(Qt::WA_TransparentForMouseEvents);

		//监听点击关卡按钮
		connect(levelBtn, &MyPushButton::clicked, [=]() {
			QString str = QString("您选择的是第 %1 关").arg(i + 1);
			qDebug() << str;
			//进入到游戏场景
			playSceneChoose = new playScene(i + 1);
            this->hide();
			playSceneChoose->show();
			//监听返回按钮
            connect(playSceneChoose, &playScene::playSceneBack, [=]() {
                playSceneChoose->hide();
                this->show();
                });
			});


	}



    qDebug() << "ChooseScene构造结束";
}

ChooseScene::~ChooseScene()
{
    qDebug() << "ChooseScene析构调用";
    qDebug() << "ChooseScene析构结束";
}
