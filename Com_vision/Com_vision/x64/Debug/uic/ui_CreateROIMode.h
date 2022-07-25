/********************************************************************************
** Form generated from reading UI file 'CreateROIMode.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEROIMODE_H
#define UI_CREATEROIMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "viewwidgets.h"

QT_BEGIN_NAMESPACE

class Ui_CreateROIMode
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    ViewWidgets *widget;
    QPushButton *pushButton_circle;
    QPushButton *pushButton_rectangular;
    QPushButton *pushButton_line;
    QPushButton *pushButton_matching;
    QWidget *tab_2;

    void setupUi(QWidget *CreateROIMode)
    {
        if (CreateROIMode->objectName().isEmpty())
            CreateROIMode->setObjectName(QStringLiteral("CreateROIMode"));
        CreateROIMode->resize(844, 665);
        gridLayout = new QGridLayout(CreateROIMode);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(CreateROIMode);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 171, 151));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 30, 115, 19));
        radioButton_3->setChecked(true);
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 70, 115, 19));
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 110, 115, 19));
        widget = new ViewWidgets(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(210, 0, 610, 641));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(85, 255, 96);"));
        pushButton_circle = new QPushButton(tab);
        pushButton_circle->setObjectName(QStringLiteral("pushButton_circle"));
        pushButton_circle->setGeometry(QRect(30, 200, 101, 28));
        pushButton_rectangular = new QPushButton(tab);
        pushButton_rectangular->setObjectName(QStringLiteral("pushButton_rectangular"));
        pushButton_rectangular->setGeometry(QRect(30, 240, 101, 28));
        pushButton_line = new QPushButton(tab);
        pushButton_line->setObjectName(QStringLiteral("pushButton_line"));
        pushButton_line->setGeometry(QRect(30, 280, 101, 28));
        pushButton_matching = new QPushButton(tab);
        pushButton_matching->setObjectName(QStringLiteral("pushButton_matching"));
        pushButton_matching->setGeometry(QRect(30, 330, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(CreateROIMode);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CreateROIMode);
    } // setupUi

    void retranslateUi(QWidget *CreateROIMode)
    {
        CreateROIMode->setWindowTitle(QApplication::translate("CreateROIMode", "CreateROIMode", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("CreateROIMode", "ROI\347\261\273\345\236\213", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("CreateROIMode", "\347\237\251\345\275\242", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("CreateROIMode", "\345\234\206\345\275\242", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("CreateROIMode", "\350\207\252\345\256\232\344\271\211", Q_NULLPTR));
        pushButton_circle->setText(QApplication::translate("CreateROIMode", "circle", Q_NULLPTR));
        pushButton_rectangular->setText(QApplication::translate("CreateROIMode", "rectangular", Q_NULLPTR));
        pushButton_line->setText(QApplication::translate("CreateROIMode", "line", Q_NULLPTR));
        pushButton_matching->setText(QApplication::translate("CreateROIMode", "template_matching", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CreateROIMode", "\346\250\241\345\274\217\351\200\211\346\213\251", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CreateROIMode", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateROIMode: public Ui_CreateROIMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEROIMODE_H
