/********************************************************************************
** Form generated from reading UI file 'ViewWidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWWIDGETS_H
#define UI_VIEWWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewWidgets
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;

    void setupUi(QWidget *ViewWidgets)
    {
        if (ViewWidgets->objectName().isEmpty())
            ViewWidgets->setObjectName(QStringLiteral("ViewWidgets"));
        ViewWidgets->resize(560, 482);
        gridLayout = new QGridLayout(ViewWidgets);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ViewWidgets);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(0, 170, 255);"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(ViewWidgets);

        QMetaObject::connectSlotsByName(ViewWidgets);
    } // setupUi

    void retranslateUi(QWidget *ViewWidgets)
    {
        ViewWidgets->setWindowTitle(QApplication::translate("ViewWidgets", "ViewWidgets", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ViewWidgets: public Ui_ViewWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWIDGETS_H
