#ifndef SHOWIMAGE_H
#define SHOWIMAGE_H
#include <QObject>
#include "QQuickPaintedItem/ImageProvider.h"

class ShowImage : public QObject
{
    Q_OBJECT
public:
    explicit ShowImage(QObject *parent = 0);
    ImageProvider *m_pImgProvider;
    Q_INVOKABLE void setTestImage();
public slots:
    void setImage(QImage image);
signals:
    void callQmlRefeshImg();
private:

    int m_ClickNum = 0;
};
#endif // SHOWIMAGE_H
