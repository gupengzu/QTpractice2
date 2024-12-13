#include "file_save_and_other.h"
#include "ui_file_save_and_other.h"
#include<QPushButton>
#include<QFileDialog>
#include<QStringConverter>
#include<QFileInfo>
#include<QDebug>
file_save_and_other::file_save_and_other(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::file_save_and_other)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[=]()
            {
        QString path=QFileDialog::getOpenFileName(this,"打开文件","E:\11111.txt");
        //将路径放入lineEdit中
        ui->lineEdit->setText(path);

        //编码格式类
        // QString content = QString::fromLocal8Bit(array);
        // ui->textEdit->setText(content);//qt6中修改成这样可以读取gbk格式


        //读取内容，放到textEdit中
        //QFile默认支持的格式是utf—8
        QFile file(path);//参数是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);

       // QByteArray array=file.readAll();
        //ui->textEdit->setText(array);

        QByteArray array;
        while(!file.atEnd())
        {
            array+=file.readLine();//按行读
        }
         ui->textEdit->setText(array);

        file.close();


        file.open(QIODevice::Append);
        file.write("aaagfg");
        file.close();


        QFileInfo info(path);
        qDebug()<<"大小："<<info.size()<<"后缀名："<<info.suffix()<<
            "文件名称："<<info.fileName()<<"文件路径"<<info.filePath()
                 <<"创建日期"<<info.birthTime().toString("yyyy//MM/dd hh:mm:ss");









    });
}

file_save_and_other::~file_save_and_other()
{
    delete ui;
}
