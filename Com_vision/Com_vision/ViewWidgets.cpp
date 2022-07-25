#include "ViewWidgets.h"
#include"halconcpp/HalconCpp.h"
#include "qevent.h"
#include <QPainter>
#include <QDebug>
using namespace HalconCpp;
//���嵥���Ŵ���
#define ZOOMRATIO 2.0
#pragma execution_character_set("utf-8") //���������������
//��ʾ����
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
	//���ɿ�ͼ��
	GenEmptyObj(&m_hCurrentImg);
	m_hHalconID = NULL;
	m_hwidgetID = (Hlong)ui->widget->winId();
	currentIndex = -1;
}

void ViewWidgets::showImage(QString fileName)
{
	if (m_hHalconID != NULL)
	{
		//�����ͼ���������ͼ��
		DetachBackgroundFromWindow(m_hHalconID);
	}
	else
	{
		//�򿪴���
		OpenWindow(0, 0, ui->widget->width(), ui->widget->height(), m_hwidgetID, "visible", "", &m_hHalconID);
	}
	setHalconWnd(m_hCurrentImg, m_hHalconID);
	std::string str = fileName.toStdString();
	ReadImage(&m_hCurrentImg, str.c_str());
	//��ȡͼ���С
	GetImageSize(m_hCurrentImg, &m_imgWidth, &m_imgHeight);
	//��ȡ����ϵ��
	TupleMin2(1.0 * ui->widget->width() / m_imgWidth, 1.0 * ui->widget->height() / m_imgHeight, &m_hvScaledRate);
	//����ͼ��
	//ZoomImageFactor(m_hCurrentImg, &m_hResizedImg, m_hvScaledRate, m_hvScaledRate, "constant");
	ZoomImageFactor(m_hCurrentImg, &m_hResizedImg, 1.0 * ui->widget->width() / m_imgWidth, 1.0 * ui->widget->height() / m_imgHeight, "constant");
	//��ȡ���ź�Ĵ�С
	GetImageSize(m_hResizedImg, &m_scaledWidth, &m_scaledHeight);
	//�򿪴���
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
		//�����ͼ���������ͼ��
		DetachBackgroundFromWindow(m_hHalconID);
	}
	else
	{
		//�򿪴���
		OpenWindow(0, 0, ui->widget->width(), ui->widget->height(), m_hwidgetID, "visible", "", &m_hHalconID);
	}
	setHalconWnd(img, m_hHalconID);
	//��ȡͼ���С
	GetImageSize(img, &m_imgWidth, &m_imgHeight);
	//��ȡ����ϵ��
	TupleMin2(1.0 * ui->widget->width() / m_imgWidth, 1.0 * ui->widget->height() / m_imgHeight, &m_hvScaledRate);
	//����ͼ��
	//ZoomImageFactor(m_hCurrentImg, &m_hResizedImg, m_hvScaledRate, m_hvScaledRate, "constant");
	ZoomImageFactor(img, &m_hResizedImg, 1.0 * ui->widget->width() / m_imgWidth, 1.0 * ui->widget->height() / m_imgHeight, "constant");
	//��ȡ���ź�Ĵ�С
	GetImageSize(m_hResizedImg, &m_scaledWidth, &m_scaledHeight);
	//�򿪴���
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

//����Halconͼ���Halcon���ھ�����û���Ӧ����¼���ʵʱ����ͼ��
void ViewWidgets::setHalconWnd(HObject img, HTuple hHalconID)
{
	m_hHalconID = hHalconID;
	m_hCurrentImg = img;
}

//�����������¼�����������ͼ��
void ViewWidgets::wheelEvent(QWheelEvent* ev)
{
	double Zoom;   //�Ŵ����С����
	HTuple  mouseRow, mouseCol, Button;
	HTuple startRowBf, startColBf, endRowBf, endColBf, Ht, Wt, startRowAft, startColAft, endRowAft, endColAft;
	//����ǰ�����Ŵ�
	if (ev->delta() > 0)
	{
		Zoom = ZOOMRATIO;
	}
	else//������С
	{
		Zoom = 1 / ZOOMRATIO;
	}
	//��ȡ�����ԭͼ�ϵ�λ�ã�ע����ԭͼ���꣬����Label�µ�����
	HTuple  hv_Exception, hv_ErrMsg;
	try
	{
		GetMposition(m_hHalconID, &mouseRow, &mouseCol, &Button);

	}
	catch (HException& HDevExpDefaultException)
	{
		return;
	}
	//��ȡԭͼ��ʾ�Ĳ��֣�ע��Ҳ��ԭͼ����
	GetPart(m_hHalconID, &startRowBf, &startColBf, &endRowBf, &endColBf);
	//����ǰ��ʾ��ͼ����
	Ht = endRowBf - startRowBf;
	Wt = endColBf - startColBf;
	//��ͨ��halcon�ܴ����ͼ�����ߴ���32K*32K�����������Сԭͼ�񣬵�����ʾ��ͼ�񳬳����ƣ������ɳ������
	if (Ht*Wt < 20000 * 20000 || Zoom == ZOOMRATIO)
	{
		//�������ź��ͼ������
		startRowAft = mouseRow - ((mouseRow - startRowBf) / Zoom);
		startColAft = mouseCol - ((mouseCol - startColBf) / Zoom);
		endRowAft = startRowAft + (Ht / Zoom);
		endColAft = startColAft + (Wt / Zoom);
		//����Ŵ�����򷵻�
		if (endRowAft - startRowAft < 2)
		{
			return;
		}

		if (m_hHalconID != NULL)
		{
			//�����ͼ���������ͼ��
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
	if (Button==1)//������
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
//	//��갴�²��ƶ�ʱ���ƶ�ͼ�񣬷���ֻ��ʾ����
//	if (Button == 1)//������
//	{
//		//�����ƶ�ֵ
//		double RowMove = mouseRow[0].D() - m_tMouseDownRow[0].D();
//		double ColMove = mouseCol[0].D() - m_tMouseDownCol[0].D();
//		//�õ���ǰ�Ĵ�������
//		GetPart(m_hHalconID, &startRowBf, &startColBf, &endRowBf, &endColBf);
//		//�ƶ�ͼ��
//		if (m_hHalconID != NULL)
//		{
//			//�����ͼ���������ͼ��
//			DetachBackgroundFromWindow(m_hHalconID);
//		}
//		SetPart(m_hHalconID, startRowBf - RowMove, startColBf - ColMove, endRowBf - RowMove, endColBf - ColMove);
//		AttachBackgroundToWindow(m_hCurrentImg, m_hHalconID);
//
//
//	}
//	else if (Button == 0)//���δ���
//	{
//		//��ʾ���� �� �Ҷ�ֵ
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
//	else if (Button == 4)//����Ҽ�
//	{
//		//����
//	}
}

void ViewWidgets::paintEvent(QPaintEvent *event)
{
	////ʵ�������Ҷ��� thisָ�����ǻ滭�豸
	//QPainter painter(this);
	////    //����
	//painter.setPen("red");
	//painter.drawLine(QPoint(0, 0), QPoint(100, 100));
}

void ViewWidgets::resizeEvent(QResizeEvent *event)
{
	//ͼ���С ���洰��仯
	HTuple Number = 0;
	CountObj(m_hCurrentImg, &Number);
	if (Number == 0) return;
	showImage(m_hCurrentImg);
}
