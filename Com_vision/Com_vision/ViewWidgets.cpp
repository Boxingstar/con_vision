#include "ViewWidgets.h"
#include"halconcpp/HalconCpp.h"
#include "qevent.h"
#include <QPainter>
#include <QDebug>
using namespace HalconCpp;
//定义单步放大倍率
#define ZOOMRATIO 2.0
#pragma execution_character_set("utf-8") //解决中文乱码问题
//显示窗体
ViewWidgets::ViewWidgets(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::ViewWidgets;
	ui->setupUi(this);
	init();

	this->setMouseTracking(true);
	ui->widget->setMouseTracking(true);
}

ViewWidgets::~ViewWidgets()
{
	delete ui;
}

void ViewWidgets::init()
{
	//生成空图像
	GenEmptyObj(&m_hCurrentImg);
	m_hHalconID = NULL;
	m_hwidgetID = (Hlong)ui->widget->winId();
	currentIndex = -1;
}

void ViewWidgets::showImage(QString fileName)
{
	if (m_hHalconID != NULL)
	{
		//如果有图像，则先清空图像
		DetachBackgroundFromWindow(m_hHalconID);
	}
	else
	{
		//打开窗口
		OpenWindow(0, 0, ui->widget->width(), ui->widget->height(), m_hwidgetID, "visible", "", &m_hHalconID);
	}
	setHalconWnd(m_hCurrentImg, m_hHalconID);
	std::string str = fileName.toStdString();
	ReadImage(&m_hCurrentImg, str.c_str());
	//获取图像大小
	GetImageSize(m_hCurrentImg, &m_imgWidth, &m_imgHeight);
	//获取缩放系数
	TupleMin2(1.0 * ui->widget->width() / m_imgWidth, 1.0 * ui->widget->height() / m_imgHeight, &m_hvScaledRate);
	//缩放图像
	//ZoomImageFactor(m_hCurrentImg, &m_hResizedImg, m_hvScaledRate, m_hvScaledRate, "constant");
	ZoomImageFactor(m_hCurrentImg, &m_hResizedImg, 1.0 * ui->widget->width() / m_imgWidth, 1.0 * ui->widget->height() / m_imgHeight, "constant");
	//获取缩放后的大小
	GetImageSize(m_hResizedImg, &m_scaledWidth, &m_scaledHeight);
	//打开窗口
	if (1.0 * ui->widget->width() / m_imgWidth < 1.0 *ui->widget->height() / m_imgHeight)
	{
		SetWindowExtents(m_hHalconID, ui->widget->height() / 2.0 - m_scaledHeight / 2.0, 0, ui->widget->width(), m_scaledHeight);
	}
	else
	{
		SetWindowExtents(m_hHalconID, 0, ui->widget->width() / 2.0 - m_scaledWidth / 2.0, m_scaledWidth, ui->widget->height());
	}
	SetPart(m_hHalconID, 0, 0, m_imgHeight - 1, m_imgWidth - 1);
	AttachBackgroundToWindow(m_hCurrentImg, m_hHalconID);
}

void ViewWidgets::showImage(HObject img)
{
	if (m_hHalconID != NULL)
	{
		//如果有图像，则先清空图像
		DetachBackgroundFromWindow(m_hHalconID);
	}
	else
	{
		//打开窗口
		OpenWindow(0, 0, ui->widget->width(), ui->widget->height(), m_hwidgetID, "visible", "", &m_hHalconID);
	}
	setHalconWnd(img, m_hHalconID);
	//获取图像大小
	GetImageSize(img, &m_imgWidth, &m_imgHeight);
	//获取缩放系数
	TupleMin2(1.0 * ui->widget->width() / m_imgWidth, 1.0 * ui->widget->height() / m_imgHeight, &m_hvScaledRate);
	//缩放图像
	//ZoomImageFactor(m_hCurrentImg, &m_hResizedImg, m_hvScaledRate, m_hvScaledRate, "constant");
	ZoomImageFactor(img, &m_hResizedImg, 1.0 * ui->widget->width() / m_imgWidth, 1.0 * ui->widget->height() / m_imgHeight, "constant");
	//获取缩放后的大小
	GetImageSize(m_hResizedImg, &m_scaledWidth, &m_scaledHeight);
	//打开窗口
	if (1.0 * ui->widget->width() / m_imgWidth < 1.0 *ui->widget->height() / m_imgHeight)
	{
		SetWindowExtents(m_hHalconID, ui->widget->height() / 2.0 - m_scaledHeight / 2.0, 0, ui->widget->width(), m_scaledHeight);
	}
	else
	{
		SetWindowExtents(m_hHalconID, 0, ui->widget->width() / 2.0 - m_scaledWidth / 2.0, m_scaledWidth, ui->widget->height());
	}
	SetPart(m_hHalconID, 0, 0, m_imgHeight - 1, m_imgWidth - 1);
	AttachBackgroundToWindow(img, m_hHalconID);
}

//设置Halcon图像和Halcon窗口句柄，用户响应鼠标事件后实时更新图像
void ViewWidgets::setHalconWnd(HObject img, HTuple hHalconID)
{
	m_hHalconID = hHalconID;
	m_hCurrentImg = img;
}

//鼠标滚轮缩放事件，用于缩放图像
void ViewWidgets::wheelEvent(QWheelEvent* ev)
{
	double Zoom;   //放大或缩小倍率
	HTuple  mouseRow, mouseCol, Button;
	HTuple startRowBf, startColBf, endRowBf, endColBf, Ht, Wt, startRowAft, startColAft, endRowAft, endColAft;
	//滚轮前滑，放大
	if (ev->delta() > 0)
	{
		Zoom = ZOOMRATIO;
	}
	else//否则缩小
	{
		Zoom = 1 / ZOOMRATIO;
	}
	//获取光标在原图上的位置，注意是原图坐标，不是Label下的坐标
	HTuple  hv_Exception, hv_ErrMsg;
	try
	{
		GetMposition(m_hHalconID, &mouseRow, &mouseCol, &Button);

	}
	catch (HException& HDevExpDefaultException)
	{
		return;
	}
	//获取原图显示的部分，注意也是原图坐标
	GetPart(m_hHalconID, &startRowBf, &startColBf, &endRowBf, &endColBf);
	//缩放前显示的图像宽高
	Ht = endRowBf - startRowBf;
	Wt = endColBf - startColBf;
	//普通版halcon能处理的图像最大尺寸是32K*32K。如果无限缩小原图像，导致显示的图像超出限制，则会造成程序崩溃
	if (Ht*Wt < 20000 * 20000 || Zoom == ZOOMRATIO)
	{
		//计算缩放后的图像区域
		startRowAft = mouseRow - ((mouseRow - startRowBf) / Zoom);
		startColAft = mouseCol - ((mouseCol - startColBf) / Zoom);
		endRowAft = startRowAft + (Ht / Zoom);
		endColAft = startColAft + (Wt / Zoom);
		//如果放大过大，则返回
		if (endRowAft - startRowAft < 2)
		{
			return;
		}

		if (m_hHalconID != NULL)
		{
			//如果有图像，则先清空图像
			DetachBackgroundFromWindow(m_hHalconID);
		}
		SetPart(m_hHalconID, startRowAft, startColAft, endRowAft, endColAft);
		AttachBackgroundToWindow(m_hCurrentImg, m_hHalconID);
	}
}

void ViewWidgets::mousePressEvent(QMouseEvent* ev)
{
	HTuple mouseRow, mouseCol, Button;
	try
	{
		GetMposition(m_hHalconID, &mouseRow, &mouseCol, &Button);
	}
	catch (HException)
	{
		return;
	}
	if (Button==1)//鼠标左键
	{
		m_tMouseDownRow = mouseRow;
		m_tMouseDownCol = mouseCol;
		m_bIsMove = true;
	} 
	else if(Button==4)
	{
		showImage(m_hCurrentImg);
	}
	
}

void ViewWidgets::mouseReleaseEvent(QMouseEvent* ev)
{
	m_bIsMove = false;
}

void ViewWidgets::mouseMoveEvent(QMouseEvent* ev)
{
//	HTuple startRowBf, startColBf, endRowBf, endColBf, mouseRow, mouseCol, Button;
//	try
//	{
//		GetMposition(m_hHalconID, &mouseRow, &mouseCol, &Button);
//
//	}
//	catch (HException)
//	{
//		return;
//	}
//
//	//鼠标按下并移动时，移动图像，否则只显示坐标
//	if (Button == 1)//鼠标左键
//	{
//		//计算移动值
//		double RowMove = mouseRow[0].D() - m_tMouseDownRow[0].D();
//		double ColMove = mouseCol[0].D() - m_tMouseDownCol[0].D();
//		//得到当前的窗口坐标
//		GetPart(m_hHalconID, &startRowBf, &startColBf, &endRowBf, &endColBf);
//		//移动图像
//		if (m_hHalconID != NULL)
//		{
//			//如果有图像，则先清空图像
//			DetachBackgroundFromWindow(m_hHalconID);
//		}
//		SetPart(m_hHalconID, startRowBf - RowMove, startColBf - ColMove, endRowBf - RowMove, endColBf - ColMove);
//		AttachBackgroundToWindow(m_hCurrentImg, m_hHalconID);
//
//
//	}
//	else if (Button == 0)//鼠标未点击
//	{
//		//显示坐标 与 灰度值
//		//do something
//		try
//		{
//			HTuple grayval, grayLength;
//			GetGrayval(m_hCurrentImg, mouseRow, mouseCol, &grayval);
//			emit sendGrayAndCoordinate_SIGNAL(grayval, mouseRow, mouseCol);
//		}
//		catch (HException)
//		{
//			return;
//		}
//
//	}
//	else if (Button == 4)//鼠标右键
//	{
//		//待定
//	}
}

void ViewWidgets::paintEvent(QPaintEvent *event)
{
	////实例化画家对象 this指定的是绘画设备
	//QPainter painter(this);
	////    //画线
	//painter.setPen("red");
	//painter.drawLine(QPoint(0, 0), QPoint(100, 100));
}

void ViewWidgets::resizeEvent(QResizeEvent *event)
{
	//图像大小 跟随窗体变化
	HTuple Number = 0;
	CountObj(m_hCurrentImg, &Number);
	if (Number == 0) return;
	showImage(m_hCurrentImg);
}
