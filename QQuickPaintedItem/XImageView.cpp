#include "XImageView.h"
#include <QPainter>

XImageView::XImageView(QQuickItem *parent ):QQuickPaintedItem(parent)
{

}
XImageView::~XImageView()
{

}
QImage XImageView::getImage() const
{
    return mImage;
}
void XImageView::setImage(QImage img)
{
    mImage = img;
}
QString XImageView::getFileUrl() const
{
    return fileUrl;
}
void XImageView::setFileUrl(QString url)
{
    fileUrl = url;
}
int XImageView::getWidth() const
{
    return mWidth;
}
void XImageView::setWidth(int w)
{
    mWidth = w;
}
int XImageView::getHeight() const
{
    return mHeight;
}
void XImageView::setHeight(int h)
{
     mHeight = h;
}
void XImageView::paint(QPainter *painter)
{
    if (painter == nullptr)
    {
        return;
    }
    if(mImage.isNull())
    {
        if(!fileUrl.isEmpty())
        {
            if(!mImage.load(fileUrl))
            {
                qDebug("load image file failed!");
                return;
            }
        }else
        {
            qDebug("file is not exsit!");
            return;
        }
    }

    QImage tempImage = mImage.scaled(mWidth*mZoom,mHeight*mZoom,Qt::KeepAspectRatio);

    painter->setRenderHint(QPainter::Antialiasing, true);
//    painter->setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true );
    painter->drawImage(0,0, tempImage);
    qDebug("paint image done !");
}
void XImageView::zoomDraw(float z )
{
    mZoom = z;
}
