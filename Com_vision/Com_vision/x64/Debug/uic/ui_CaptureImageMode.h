/********************************************************************************
** Form generated from reading UI file 'CaptureImageMode.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTUREIMAGEMODE_H
#define UI_CAPTUREIMAGEMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "viewwidgets.h"

QT_BEGIN_NAMESPACE

class Ui_CaptureImageMode
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *captureModeTab;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QRadioButton *cameraCaptureImgRBtn;
    QRadioButton *imageFileRBtn;
    QRadioButton *imageDocRbtn;
    QGroupBox *groupBox_2;
    QLineEdit *imageNamelE;
    QPushButton *getImageBtn;
    QWidget *paraTab;
    ViewWidgets *imgWidget;

    void setupUi(QWidget *CaptureImageMode)
    {
        if (CaptureImageMode->objectName().isEmpty())
            CaptureImageMode->setObjectName(QStringLiteral("CaptureImageMode"));
        CaptureImageMode->resize(753, 579);
        gridLayout = new QGridLayout(CaptureImageMode);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(CaptureImageMode);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        captureModeTab = new QWidget();
        captureModeTab->setObjectName(QStringLiteral("captureModeTab"));
        widget = new QWidget(captureModeTab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 10, 171, 511));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        cameraCaptureImgRBtn = new QRadioButton(groupBox);
        cameraCaptureImgRBtn->setObjectName(QStringLiteral("cameraCaptureImgRBtn"));
        cameraCaptureImgRBtn->setGeometry(QRect(20, 30, 115, 19));
        imageFileRBtn = new QRadioButton(groupBox);
        imageFileRBtn->setObjectName(QStringLiteral("imageFileRBtn"));
        imageFileRBtn->setEnabled(true);
        imageFileRBtn->setGeometry(QRect(20, 60, 115, 19));
        imageFileRBtn->setMouseTracking(true);
        imageFileRBtn->setAcceptDrops(false);
        imageFileRBtn->setChecked(true);
        imageDocRbtn = new QRadioButton(groupBox);
        imageDocRbtn->setObjectName(QStringLiteral("imageDocRbtn"));
        imageDocRbtn->setGeometry(QRect(20, 90, 115, 19));

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        imageNamelE = new QLineEdit(groupBox_2);
        imageNamelE->setObjectName(QStringLiteral("imageNamelE"));
        imageNamelE->setGeometry(QRect(10, 40, 151, 21));
        getImageBtn = new QPushButton(groupBox_2);
        getImageBtn->setObjectName(QStringLiteral("getImageBtn"));
        getImageBtn->setGeometry(QRect(30, 80, 93, 28));

        verticalLayout->addWidget(groupBox_2);

        tabWidget->addTab(captureModeTab, QString());
        paraTab = new QWidget();
        paraTab->setObjectName(QStringLiteral("paraTab"));
        tabWidget->addTab(paraTab, QString());

        horizontalLayout->addWidget(tabWidget);

        imgWidget = new ViewWidgets(CaptureImageMode);
        imgWidget->setObjectName(QStringLiteral("imgWidget"));

        horizontalLayout->addWidget(imgWidget);

        horizontalLayout->setStretch(1, 4);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(CaptureImageMode);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CaptureImageMode);
    } // setupUi

    void retranslateUi(QWidget *CaptureImageMode)
    {
        CaptureImageMode->setWindowTitle(QApplication::translate("CaptureImageMode", "\345\233\276\345\203\217\351\207\207\351\233\206", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CaptureImageMode", "\345\233\276\345\203\217\346\250\241\345\274\217", Q_NULLPTR));
        cameraCaptureImgRBtn->setText(QApplication::translate("CaptureImageMode", "\347\233\270\346\234\272\345\217\226\345\233\276", Q_NULLPTR));
        imageFileRBtn->setText(QApplication::translate("CaptureImageMode", "\345\233\276\345\203\217\346\226\207\344\273\266", Q_NULLPTR));
        imageDocRbtn->setText(QApplication::translate("CaptureImageMode", "\345\233\276\345\203\217\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("CaptureImageMode", "GroupBox", Q_NULLPTR));
        getImageBtn->setText(QApplication::translate("CaptureImageMode", "\350\216\267\345\217\226\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(captureModeTab), QApplication::translate("CaptureImageMode", "\351\207\207\351\233\206\346\250\241\345\274\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(paraTab), QApplication::translate("CaptureImageMode", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CaptureImageMode: public Ui_CaptureImageMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTUREIMAGEMODE_H
