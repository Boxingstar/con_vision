#pragma once

#include <QWidget>
#include "ui_ViewWidgets.h"
#include"halconcpp/HalconCpp.h"
#include <QLabel>
#include "qevent.h"

using namespace HalconCpp;
#pragma execution_character_set("utf-8") //解决中文乱码问题
class ViewWidgets : public QWidget
{
	Q_OBJECT

public:
	ViewWidgets(QWidget *parent = Q_NULLPTR);
	~ViewWidgets();
	HTuple m_hHalconID;                                      //Halcon显示窗口句柄					
	void showImage(QString fileName);	                      //显示图像
	void showImage(HObject  img);	                          //显示图像
signals:                                                      //灰度值坐标信号
	void sendGrayAndCoordinate_SIGNAL(HTuple gray, HTuple row, HTuple col);
	public slots:

private:
	Ui::ViewWidgets* ui;

	void init();                                               //初始化
	void setHalconWnd(HObject img, HTuple hHalconID);

	int currentIndex;
	HTuple m_hwidgetID;                                      //Widget控件句柄
	
	HTuple m_imgWidth, m_imgHeight;                          //原始图像的尺寸

	HTuple m_imgFiles;                                   	//图片路径列表
	HObject m_hCurrentImg;                                  //当前图像
	HObject m_hResizedImg;                                  //缩放后的图像
	HTuple m_hvScaledRate;	                                //缩放系数
	HTuple m_scaledHeight, m_scaledWidth;               	//缩放后图像的大小

	//鼠标按下的位置 
	HTuple m_tMouseDownRow;
	HTuple m_tMouseDownCol;
	bool m_bIsMove;                                        //是否移动图像标识

	void wheelEvent(QWheelEvent* ev); 		              //鼠标滚轮缩放事件
	void mousePressEvent(QMouseEvent* ev);	              //鼠标按下事件	
	void mouseReleaseEvent(QMouseEvent* ev);              //鼠标释放事件	
	void mouseMoveEvent(QMouseEvent* ev);                 //鼠标移动事件
	void paintEvent(QPaintEvent *event);                  //界面绘制
	void resizeEvent(QResizeEvent *event);
};
