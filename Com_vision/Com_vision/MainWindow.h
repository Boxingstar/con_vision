#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include"halconcpp/HalconCpp.h"
#include "CreateROIMode.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:

	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

	CreateROIMode *crm;
	


private:
	Ui::MainWindowClass *ui;

	private slots:
	void on_loadParaBtn_clicked();
	void on_virtualKeyboardBtn_clicked();
	void on_captureImgBtn_clicked();
	void on_QRCodeBtn_clicked();
	void on_creatROIBtn_clicked();
	void display_gray_coordinate(HTuple gray, HTuple row, HTuple col);
	void on_tempMatchBtn_clicked();
};
