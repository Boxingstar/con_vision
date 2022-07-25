#include "CaptureImageMode.h"
#include <QDebug>
#include "QFileDialog"

#pragma execution_character_set("utf-8") //���������������

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
	QString filter = "ͼƬ�ļ�(*.jpg *.bmp *.png *.gif *.hobj *.ima *.jp2 *.jpeg *.jxr *.pbm *.pcx *.pgm *.pnm *.ppm *.ras *.tif *.tiff *.xwd)"; //�ļ�������
	QString imgName = QFileDialog::getOpenFileName(this, "ѡ��ͼƬ", "", filter);
	if (imgName.isEmpty()) return NULL;
	return imgName;
}

void CaptureImageMode::on_getImageBtn_clicked()
{
	qDebug() << "��ȡͼ��";
	QString imgName = selectImageFile();
	if (imgName!=NULL)
	{
		ui->imageNamelE->setText(imgName);
		ui->imgWidget->showImage(imgName);
	}
	
}
