#include "CaptureImageMode.h"
#include <QDebug>
#include "QFileDialog"

#pragma execution_character_set("utf-8") //解决中文乱码问题

using namespace HalconCpp;
CaptureImageMode::CaptureImageMode(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::CaptureImageMode;
	ui->setupUi(this);
}

CaptureImageMode::~CaptureImageMode()
{

}

QString CaptureImageMode::selectImageFile()
{
	QString filter = "图片文件(*.jpg *.bmp *.png *.gif *.hobj *.ima *.jp2 *.jpeg *.jxr *.pbm *.pcx *.pgm *.pnm *.ppm *.ras *.tif *.tiff *.xwd)"; //文件过滤器
	QString imgName = QFileDialog::getOpenFileName(this, "选择图片", "", filter);
	if (imgName.isEmpty()) return NULL;
	return imgName;
}

void CaptureImageMode::on_getImageBtn_clicked()
{
	qDebug() << "获取图像";
	QString imgName = selectImageFile();
	if (imgName!=NULL)
	{
		ui->imageNamelE->setText(imgName);
		ui->imgWidget->showImage(imgName);
	}
	
}
