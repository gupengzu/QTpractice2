#pragma once

#include <QtWidgets/QMainWindow>
#include "ui__QtSource.h"

class _QtSource : public QMainWindow
{
    Q_OBJECT

public:
    _QtSource(QWidget *parent = nullptr);
    ~_QtSource();

private:
    Ui::_QtSourceClass ui;
};
