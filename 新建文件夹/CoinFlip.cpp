#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include "CoinFlip.h"
#include <QPainter>
#include <MyPushButton.h>
#include <QMenuBar>
#include <QTimer>

#include <QDebug>

CoinFlip::CoinFlip(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << "CoinFlip 构造函数开始";
    ui.setupUi(this);
    //设置对话框固定大小
    this->setFixedSize(400, 588);
    //设置对话框标题
    this->setWindowTitle("Coin Flip");
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
    closeBtn->move(this->width() - closeBtn->width(), this->height()-closeBtn->height());
    //设置开始按钮
    MyPushButton* startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()/2 - startBtn->width() / 2, this->height() - startBtn->height()-50);
    
    // 创建选择关卡场景
    //qDebug() << "创建 ChooseScene 实例";
    chooseScene = new ChooseScene;
    //qDebug() << "ChooseScene 实例创建完成";

    // 监听点击事件
    connect(startBtn, &MyPushButton::clicked, [=]() {
        //qDebug() << "点击了开始按钮";
        startBtn->zoom1();
        startBtn->zoom2();

        QTimer::singleShot(200, this, [=]() {
            // 隐藏当前窗口
            this->hide();
            // 显示选择关卡场景
            chooseScene->show();
        });
    });


	//连接返信号到槽函数
	connect(chooseScene, &ChooseScene::chooseSceneBack, [=]() {
		//qDebug() << "接收到了返回信号";
		chooseScene->hide();
		this->show();
		});

	connect(closeBtn, &MyPushButton::clicked, [=]() {
            this->close();
		});


    //qDebug() << "CoinFlip 构造函数结束";
}

// 添加图片
void CoinFlip::paintEvent(QPaintEvent* event)
{
    QPixmap pix;
    pix.load(":/res/Title.png");
    QPainter painter(this);
    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
}

CoinFlip::~CoinFlip()
{
    qDebug() << "CoinFlip 析构函数";
    delete chooseScene;
}
