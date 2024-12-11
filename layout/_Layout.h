#pragma once

#include <QtWidgets/QMainWindow>
#include "ui__Layout.h"

class _Layout : public QMainWindow
{
    Q_OBJECT

public:
    _Layout(QWidget *parent = nullptr);
    ~_Layout();

private:
    Ui::_LayoutClass ui;
};
