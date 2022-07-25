#include "MainWindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include <QDebug>
#include <Windows.h>
#include "CaptureImageMode.h"

#pragma comment(lib, "user32.lib")

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::MainWindowClass;
	ui->setupUi(this);
	//灰度坐标显示信号槽
	connect(ui->UIwidget, &ViewWidgets::sendGrayAndCoordinate_SIGNAL, this, &MainWindow::display_gray_coordinate);
}

MainWindow::~MainWindow()
{
	delete ui;
	delete crm;
}

void MainWindow::on_loadParaBtn_clicked()
{
	QString filter = "图片文件(*.jpg *.bmp *.png)"; //文件过滤器
	QString imgName = QFileDialog::getOpenFileName(this, "", "", filter);
	if (imgName.isEmpty())return;
	ui->UIwidget->showImage(imgName);
}

void MainWindow::on_virtualKeyboardBtn_clicked()
{
	//win8.1   win10 下使用
	PVOID OldValue = nullptr;
	BOOL bRet = Wow64DisableWow64FsRedirection(&OldValue);
	QString csProcess = "C:\\Windows\\System32\\osk.exe";
	QString params = "";
	ShellExecute(nullptr, L"open", (LPCWSTR)csProcess.utf16(), (LPCWSTR)params.utf16(), nullptr, SW_SHOWNORMAL);
	if (bRet)
	{
		Wow64RevertWow64FsRedirection(OldValue);
	}
}

void MainWindow::on_captureImgBtn_clicked()
{
	qDebug() << "采集图像";
	CaptureImageMode* capImg = new CaptureImageMode;
	capImg->show();
}

void MainWindow::on_QRCodeBtn_clicked()
{
	qDebug() << "二维码识别";
}

void MainWindow::on_creatROIBtn_clicked()
{
	qDebug() << "创建ROI";
	crm = new CreateROIMode;
	//CreateROIMode* creatROI = new CreateROIMode;
	crm->show();
}

void MainWindow::display_gray_coordinate(HTuple gray, HTuple row, HTuple col)
{
	HTuple grayLength;
	TupleLength(gray, &grayLength);
	grayLength > 1 ?
		ui->status_label->setText("Row:" + QString::number(row.I()) + " " + "Col:" + QString::number(col.I()) + " " + " R:" + QString::number(gray[0].I()) + " G:" + QString::number(gray[1].I()) + " B:" + QString::number(gray[2].I())) :
		ui->status_label->setText("Row:" + QString::number(row.I()) + " " + "Col:" + QString::number(col.I()) + " " + "Gray:" + QString::number(gray.I()));
}

void MainWindow::on_tempMatchBtn_clicked()
{
	qDebug("hello");
	//GetDrawingObjectParams(crm->roi_window, ((HTuple("row").Append("column")).Append("radius")), &hv_GenParamValue);
	HTuple a=crm->get_return_value();
	double tem = a[1];
	//HString str = hv_GenParamValue[1].S();
	//char* code = const_cast<char*>(str.Text());
	qDebug() << QString::number(tem);
	//DrawCircle(ui->widget->m_hHalconID, &HTuple(hv_GenParamValue[0]), &HTuple(hv_GenParamValue[1]), &HTuple(hv_GenParamValue[2]));
	//GenCircleContourXld(ContCircle, hv_GenParamValue[0], hv_GenParamValue[1], hv_GenParamValue[2], 0, 6.28318, "positive", 1);
}
