#include "Video_Player_OpenGL_Show_Image.h"

Video_Player_OpenGL_Show_Image::Video_Player_OpenGL_Show_Image()
{

}

void Video_Player_OpenGL_Show_Image::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    QImage image;
    image.load("/Users/yangwei/Downloads/2.jpeg");
    //设置图像自适应窗口大小
    QImage result = image.scaled(this->width(),this->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    painter.drawImage(QPoint(0,0),result);
    painter.end();

}
