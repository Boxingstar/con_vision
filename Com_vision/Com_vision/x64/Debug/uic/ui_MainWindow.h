/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "viewwidgets.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *action1;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *loadParaBtn;
    QPushButton *virtualKeyboardBtn;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QWidget *widget_3;
    QPushButton *captureImgBtn;
    QPushButton *QRCodeBtn;
    QPushButton *creatROIBtn;
    QPushButton *tempMatchBtn;
    QGridLayout *gridLayout;
    ViewWidgets *UIwidget;
    QWidget *widget_5;
    QLabel *status_label;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1084, 833);
        action1 = new QAction(MainWindowClass);
        action1->setObjectName(QStringLiteral("action1"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        loadParaBtn = new QPushButton(widget);
        loadParaBtn->setObjectName(QStringLiteral("loadParaBtn"));
        loadParaBtn->setGeometry(QRect(430, 40, 93, 28));
        virtualKeyboardBtn = new QPushButton(widget);
        virtualKeyboardBtn->setObjectName(QStringLiteral("virtualKeyboardBtn"));
        virtualKeyboardBtn->setGeometry(QRect(870, 30, 131, 41));

        verticalLayout->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(20, 0, 127, 643));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        captureImgBtn = new QPushButton(widget_3);
        captureImgBtn->setObjectName(QStringLiteral("captureImgBtn"));
        captureImgBtn->setGeometry(QRect(10, 20, 93, 28));
        QRCodeBtn = new QPushButton(widget_3);
        QRCodeBtn->setObjectName(QStringLiteral("QRCodeBtn"));
        QRCodeBtn->setGeometry(QRect(10, 60, 93, 28));
        creatROIBtn = new QPushButton(widget_3);
        creatROIBtn->setObjectName(QStringLiteral("creatROIBtn"));
        creatROIBtn->setGeometry(QRect(10, 110, 93, 28));
        tempMatchBtn = new QPushButton(widget_3);
        tempMatchBtn->setObjectName(QStringLiteral("tempMatchBtn"));
        tempMatchBtn->setGeometry(QRect(10, 170, 93, 28));

        horizontalLayout->addWidget(widget_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        UIwidget = new ViewWidgets(centralWidget);
        UIwidget->setObjectName(QStringLiteral("UIwidget"));
        UIwidget->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(UIwidget, 0, 0, 1, 1);

        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(widget_5, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setRowStretch(1, 1);

        horizontalLayout_2->addLayout(gridLayout);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 7);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QStringLiteral("status_label"));

        gridLayout_2->addWidget(status_label, 1, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1084, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        action1->setText(QApplication::translate("MainWindowClass", "\344\270\255\346\226\207", Q_NULLPTR));
        loadParaBtn->setText(QApplication::translate("MainWindowClass", "\345\212\240\350\275\275\345\233\276\345\203\217", Q_NULLPTR));
        virtualKeyboardBtn->setText(QApplication::translate("MainWindowClass", "\350\231\232\346\213\237\351\224\256\347\233\230", Q_NULLPTR));
        captureImgBtn->setText(QApplication::translate("MainWindowClass", "\345\233\276\345\203\217\351\207\207\351\233\206", Q_NULLPTR));
        QRCodeBtn->setText(QApplication::translate("MainWindowClass", "\344\272\214\347\273\264\347\240\201\350\257\206\345\210\253", Q_NULLPTR));
        creatROIBtn->setText(QApplication::translate("MainWindowClass", "\345\210\233\345\273\272ROI", Q_NULLPTR));
        tempMatchBtn->setText(QApplication::translate("MainWindowClass", "\346\250\241\346\235\277\345\214\271\351\205\215", Q_NULLPTR));
        status_label->setText(QApplication::translate("MainWindowClass", "TextLabel", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindowClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindowClass", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
