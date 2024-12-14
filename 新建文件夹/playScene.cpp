#include "playScene.h"
#include "QLabel"
#include <qmenubar.h>
#include "MyPushButton.h"
#include <QTimer>
#include <QDebug>

playScene::playScene(int levelNumber)
{
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
    closeBtn->move(this->width() - closeBtn->width(), this->height() - closeBtn->height());
    //连接点击事件到返回信号
    connect(closeBtn, &MyPushButton::clicked, [=]() {
        //返回按钮特效
        closeBtn->zoom1();
        closeBtn->zoom2();
        //延时返回
        QTimer::singleShot(200, this, [=]() {
            //发射自定义信号，告诉选关场景 我要返回了
            emit playSceneBack();
        });
    });

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            QPixmap pixmap = QPixmap(":/res/BoardNode(1).png");
            QLabel* label = new QLabel(this);
            label->setGeometry(100 + i * 50, 200 + j * 50, 50, 50);
            label->setPixmap(pixmap);
            dataConfig* data = new dataConfig;
            QVector< QVector<int>> v = data->mData.value(levelNumber);
            if (v[i][j] == 1)
            {
				MyCoin* coin = new MyCoin(100 + i * 50, 200 + j * 50, true);
				coin->setParent(this);
				coin->move(100 + i * 50, 200 + j * 50);
				coins.push_back(coin);
            }
            else
            {
				MyCoin* coin = new MyCoin(100 + i * 50, 200 + j * 50, false);
				coin->setParent(this);
				coin->move(100 + i * 50, 200 + j * 50);
				coins.push_back(coin);

            }

            connect(coins[i * 4 + j], &MyCoin::clicked, [=]()
            {
                qDebug() << "Coin clicked at: " << i << ", " << j;
                // 翻转自身
     
                coins[i * 4 + j]->changeIcon();
                // 翻转周围硬币
                if (i > 0)
                {
   
                    coins[(i - 1) * 4 + j]->changeIcon();
                }
                if (i < 3)
                {

                    coins[(i + 1) * 4 + j]->changeIcon();
                }
                if (j > 0)
                {

                    coins[i * 4 + j - 1]->changeIcon();
                }
                if (j < 3)
                {
     
                    coins[i * 4 + j + 1]->changeIcon();
                }

                connect(coins[i * 4 + j], &MyCoin::flipFinished, [=]()
                    {
                        // 检查胜利条件
                        bool win = true;
                        for (int k = 0; k < 4; k++)
                        {
                            for (int l = 0; l < 4; l++)
                            {
                                if (!coins[k * 4 + l]->flag)
                                {
                                    win = false;
                                    break;
                                }
                            }
                            if (!win) break;
                        }


                        if (win)
                        {
                            qDebug() << "You win!";
                            //显示胜利图片
                            QLabel* winLabel = new QLabel(this);
                            QPixmap winPixmap = QPixmap(":/res/LevelCompletedDialogBg.png");
                            winLabel->setGeometry(0, 0, winPixmap.width(), winPixmap.height());
                            winLabel->setPixmap(winPixmap);
                            winLabel->move((this->width() - winPixmap.width()) / 2, (this->height() - winPixmap.height()) / 2);
                            winLabel->show();
                            //终止所有硬币翻转
                            for (int m = 0; m < 4; m++)
                            {
                                for (int n = 0; n < 4; n++)
                                {
                                    coins[m * 4 + n]->timer1->stop();
                                }
                            }
                        }
                    });
          

            });
            
        }
    }
}

playScene::~playScene()
{
}
