#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Q1.h"

class Q1 : public QMainWindow
{
    Q_OBJECT

public:
    Q1(QWidget *parent = Q_NULLPTR);

private:
    Ui::Q1Class ui;
};
