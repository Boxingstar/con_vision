#pragma once

#include <QWidget>
#include "ui_ViewWidgets.h"
#include"halconcpp/HalconCpp.h"
#include <QLabel>
#include "qevent.h"

using namespace HalconCpp;
#pragma execution_character_set("utf-8") //���������������
class ViewWidgets : public QWidget
{
	Q_OBJECT

public:
	ViewWidgets(QWidget *parent = Q_NULLPTR);
	~ViewWidgets();
	HTuple m_hHalconID;                                      //Halcon��ʾ���ھ��					
	void showImage(QString fileName);	                      //��ʾͼ��
	void showImage(HObject  img);	                          //��ʾͼ��
signals:                                                      //�Ҷ�ֵ�����ź�
	void sendGrayAndCoordinate_SIGNAL(HTuple gray, HTuple row, HTuple col);
	public slots:

private:
	Ui::ViewWidgets* ui;

	void init();                                               //��ʼ��
	void setHalconWnd(HObject img, HTuple hHalconID);

	int currentIndex;
	HTuple m_hwidgetID;                                      //Widget�ؼ����
	
	HTuple m_imgWidth, m_imgHeight;                          //ԭʼͼ��ĳߴ�

	HTuple m_imgFiles;                                   	//ͼƬ·���б�
	HObject m_hCurrentImg;                                  //��ǰͼ��
	HObject m_hResizedImg;                                  //���ź��ͼ��
	HTuple m_hvScaledRate;	                                //����ϵ��
	HTuple m_scaledHeight, m_scaledWidth;               	//���ź�ͼ��Ĵ�С

	//��갴�µ�λ�� 
	HTuple m_tMouseDownRow;
	HTuple m_tMouseDownCol;
	bool m_bIsMove;                                        //�Ƿ��ƶ�ͼ���ʶ

	void wheelEvent(QWheelEvent* ev); 		              //�����������¼�
	void mousePressEvent(QMouseEvent* ev);	              //��갴���¼�	
	void mouseReleaseEvent(QMouseEvent* ev);              //����ͷ��¼�	
	void mouseMoveEvent(QMouseEvent* ev);                 //����ƶ��¼�
	void paintEvent(QPaintEvent *event);                  //�������
	void resizeEvent(QResizeEvent *event);
};
