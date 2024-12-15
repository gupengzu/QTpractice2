#pragma once

#include <QtWidgets/QMainWindow>
#include "ui__QDialog.h"

class _QDialog : public QMainWindow
{
    Q_OBJECT

public:
    _QDialog(QWidget *parent = nullptr);
    ~_QDialog();

private:
    Ui::_QDialogClass ui;
};
