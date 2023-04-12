#ifndef XIMAGEVIEW_H
#define XIMAGEVIEW_H

#include <QObject>
#include <QImage>
#include <QQuickPaintedItem>

class QPainter;
class XImageView : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QImage mImage READ getImage WRITE setImage)
    Q_PROPERTY(QString fileUrl READ getFileUrl WRITE setFileUrl)
    Q_PROPERTY(int mWidth READ getWidth WRITE setWidth)
    Q_PROPERTY(int mHeight READ getHeight WRITE setHeight)

public:
    XImageView(QQuickItem *parent = 0);
    virtual ~XImageView();

    virtual void paint(QPainter *painter);

    QImage getImage() const;
    void setImage(QImage img);

    QString getFileUrl() const;
    void setFileUrl(QString url);

    int getWidth() const;
    void setWidth(int w);

    int getHeight() const;
    void setHeight(int h);

    Q_INVOKABLE void zoomDraw(float z = 1.0f);

private:
   QImage mImage;
   QString fileUrl;
   int mWidth;
   int mHeight;
   float mZoom;
};

#endif // XIMAGEVIEW_H

