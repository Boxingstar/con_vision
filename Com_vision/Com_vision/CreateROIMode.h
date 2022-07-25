#pragma once

#include <QWidget>
#include "ui_CreateROIMode.h"

class CreateROIMode : public QWidget
{
	Q_OBJECT

public:
	CreateROIMode(QWidget *parent = Q_NULLPTR);

	~CreateROIMode();

	HTuple roi_window;
	HTuple roi_window1;
	HTuple roi_window2;

	void CreateROIMode::createROI(double midX, double midY);
	HTuple get_return_value();

private:

	Ui::CreateROIMode* ui;

	HTuple hv_GenParamValue;

	private slots:
	void on_pushButton_circle_clicked();
	HTuple on_pushButton_line_clicked();
	HTuple on_pushButton_rectangular_clicked();
	void on_pushButton_matching_clicked();

};
