#pragma once

#include <QtWidgets/QWidget>
#include "ui_CoinFlip.h"
#include "ChooseScene.h"

class CoinFlip : public QWidget
{
    Q_OBJECT

public:
    CoinFlip(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent* event);
    ChooseScene* chooseScene = nullptr;

    ~CoinFlip();

//private slots:
//    void handleChooseSceneBack(); // 槽函数

private:
    Ui::CoinFlipClass ui;
};
