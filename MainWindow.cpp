#include "MainWindow.h"
#include <QQuickItem>
#include <QDesktopServices>
#include <QStandardPaths>
#include <QUrl>
#include <QQmlApplicationEngine>
#include <QQmlContext>


MainWindow* theWnd= nullptr;

QQmlEngine* MainWindow::sEngine = nullptr;
void MainWindow::registerObject(QQmlEngine* engine)
{
    sEngine = engine;
    // 注册
    qRegisterMetaType<uchar*>("uchar*");
    qmlRegisterType<MainWindow>("Custon.Control",1, 0, "MainWindow");

}

MainWindow::MainWindow(QWindow *parent)
    : QQuickWindow(parent)
{
    theWnd = this;

//    sEngine->addImageProvider(QLatin1String("video"), new ImageProvider());



//    EditorAdapter* editorAdapter = new EditorAdapter();
//    editorAdapter->open();
//    sEngine->rootContext()->setContextProperty("editorAdapter", editorAdapter);
//    m_objects.push_back(editorAdapter);

}

MainWindow::~MainWindow()
{
    //逆序析构，解决依赖关系
    for(auto iter = m_objects.rbegin(); iter != m_objects.rend(); iter++)
    {
        delete (*iter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QQuickWindow::mousePressEvent(event);

    QQuickItem* item = activeFocusItem();
    if(item){
        QVariant userProperty = item->property("autoFocus");
        if(userProperty.isValid() && userProperty.toBool())
        {
            QPointF itemTopLeft = item->mapToGlobal(QPointF(0,0));
            QRectF rc(itemTopLeft.x(), itemTopLeft.y(), item->width(), item->height());
            if(!rc.contains(event->globalPosition())){
                item->setFocus(false);
            }
        }
    }
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QQuickWindow::keyPressEvent(event);

    if(event->key() == Qt::Key_F12){
        //F12执行测试代码
      qDebug()<<"按下了 F12按钮 ";
    }else if(event->key() == Qt::Key_F11 && (event->modifiers()& Qt::ControlModifier)){
        //Ctrl + F11打开资源目录
        QStringList paths = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
        QDesktopServices::openUrl(QUrl::fromLocalFile(paths.first()));
    }
}
