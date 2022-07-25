#include "CreateROIMode.h"
#include<Qdebug.h>
//#include "ViewWidgets.h"

CreateROIMode::CreateROIMode(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::CreateROIMode;
	ui->setupUi(this);
	ViewWidgets vw;
	//mw = new MainWindow;
	ui->widget->showImage("C:\\Users\\xiao\'xin\\Desktop\\¿Ì¶È³ß.jpg");
}

CreateROIMode::~CreateROIMode()
{

}

void CreateROIMode::on_pushButton_circle_clicked()
{
	//CreateDrawingObjectCircle(*circle_row, *circle_column, *circle_radius, &roi_window);
	CreateDrawingObjectCircle(1000, 1000, 500, &roi_window);
	SetDrawingObjectParams(roi_window, "color", "yellow");
	AttachDrawingObjectToWindow(ui->widget->m_hHalconID, roi_window);
	//GetDrawingObjectParams(*TEST, ((HTuple("row").Append("column")).Append("radius")),&result);
	return;
}

HTuple CreateROIMode::get_return_value()
{
	qDebug("hello");
	HTuple tem1 = roi_window;
	GetDrawingObjectParams(roi_window, ((HTuple("row").Append("column")).Append("radius")), &hv_GenParamValue);

	double tem = hv_GenParamValue[1];
	qDebug() << QString::number(tem);
	return hv_GenParamValue;
}

HTuple CreateROIMode::on_pushButton_line_clicked()
{
	CreateDrawingObjectLine(500, 500, 1000, 1000, &roi_window1);
	SetDrawingObjectParams(roi_window1, "color", "yellow");
	AttachDrawingObjectToWindow(ui->widget->m_hHalconID, roi_window1);
	return roi_window1;

	//DrawLine(ui->widget->m_hHalconID, line_row1, line_column1, line_row2, line_column2);
}

HTuple CreateROIMode::on_pushButton_rectangular_clicked()
{
	CreateDrawingObjectRectangle1(500, 500, 1000, 1000, &roi_window2);
	SetDrawingObjectParams(roi_window2, "color", "yellow");
	AttachDrawingObjectToWindow(ui->widget->m_hHalconID, roi_window2);
	return roi_window2;
}

void CreateROIMode::on_pushButton_matching_clicked()
{
	qDebug("hello");

	GetDrawingObjectParams(roi_window, ((HTuple("row").Append("column")).Append("radius")), &hv_GenParamValue);

	double tem = hv_GenParamValue[1];
	qDebug() << QString::number(tem);
}
