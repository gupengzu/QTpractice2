#pragma once

#include <QWidget>
#include"playScene.h"
class ChooseScene : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseScene(QWidget* parent = nullptr);
    playScene* playSceneChoose = nullptr;
    ~ChooseScene() override;

signals:
    void chooseSceneBack(); // 自定义信号

};