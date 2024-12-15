#include "_QDialog.h"
#include<qdialog>
#include<qdebug.h>
#include <QMessageBox>
#include<qcolor.h>
#include <QColorDialog>
#include <QFileDialog>
#include <QString>
#include <QFontDialog>
_QDialog::_QDialog(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //点击新建按钮 弹出一个对话框
    connect(ui.actionnew, &QAction::triggered, [=]() {
        //对话框 分类
        //模态对话框（不可以对其他窗口进行操作） 非模态对话框（可以对其他窗口进行操作）
        //模态创建 阻塞
        //QDialog dlg(this);
        //dlg.resize(200, 100);
        //dlg.exec();

        //qDebug() << "模态对话框弹出了";


        //非模态对话框
        QDialog *dlg2=new QDialog(this);
        dlg2->resize(200, 100);
        dlg2->show();
        dlg2->setAttribute(Qt::WA_DeleteOnClose);
        qDebug() << "非模态对话框";


        //消息对话框
        //错误对话框
        //QMessageBox::critical(this, "critical", "错误");

        //信息对话框
        //QMessageBox::information(this, "info", "信息");

        //提问对话框
        //if (QMessageBox::question(this, "ques", "提问") == QMessageBox::Yes)
        //{
          //  qDebug() << "yes";
        //}
        //警告
        //QMessageBox::warning(this, "warning", "警告");


        //其他
        //颜色
        //QColor color=QColorDialog::getColor(QColor(255, 15, 25));

        //qDebug() << "r=" << color.red() << "b=" << color.blue();
        //文件
        //QString str=QFileDialog::getOpenFileName(this, "打开文件", "G:\\","*.txt");
        //字体
        bool flag;
        QFont font=QFontDialog::getFont(&flag, QFont("华文彩云", 36));
        qDebug() << font.pointSize() << font.bold();
        });

   
} 

_QDialog::~_QDialog()
{}
