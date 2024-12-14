#pragma once

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT

public:
    MyCoin(int x, int y, bool f);

    // 翻转
    void changeIcon();

    // 金币属性
    int posX;
    int posY;
    bool flag; // 正反标志

    QTimer* timer1; // 硬币翻转 定时器
    int min;
    int max;

    ~MyCoin();

signals:
    void flipFinished();
};
