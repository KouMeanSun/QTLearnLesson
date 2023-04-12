#include "ShowImage.h"
#include <QDebug>

ShowImage::ShowImage(QObject *parent) :
    QObject(parent)
{
    m_pImgProvider = new ImageProvider();
}
void ShowImage::setImage(QImage image)
{
    m_pImgProvider->img = image;
    emit callQmlRefeshImg();
    qDebug()<<"ShowImage callQmlRefeshImg";
}

void ShowImage::setTestImage()
{
        QImage img;
        bool isLoaded ;
        if(m_ClickNum%2==0){
              isLoaded = img.load("C:/Users/gaomingyang.000/Desktop/25.jpg");
        }else{
            isLoaded = img.load("C:/Users/gaomingyang.000/Desktop/building.jpg");
        }

        qDebug()<<"ImageProvider isLoaded:"<<isLoaded;
        this->setImage(img);
        m_ClickNum++;
}
