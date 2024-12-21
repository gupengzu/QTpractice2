#include "_QtSource.h"

_QtSource::_QtSource(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //ui.actionnew->setIcon(QIcon("G:\\photos\\41117161321.jpg"));

    //使用添加Qt资源":+前缀名+文件名"
    ui.actionnew->setIcon(QIcon(":/_QtSource/photos/test2.png"));
    ui.actionopen->setIcon(QIcon(":/photos/bk.jpg"));
}

_QtSource::~_QtSource()
{}
