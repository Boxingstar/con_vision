#pragma once

#include <QWidget>
#include "ui_CaptureImageMode.h"

class CaptureImageMode : public QWidget
{
	Q_OBJECT

public:
	CaptureImageMode(QWidget *parent = Q_NULLPTR);
	~CaptureImageMode();

private:
	Ui::CaptureImageMode* ui;


	QString selectImageFile();
	private slots:
	void on_getImageBtn_clicked();
};
