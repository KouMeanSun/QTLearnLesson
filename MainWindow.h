#ifndef QUICKWINDOW_H
#define QUICKWINDOW_H
#include <QQuickWindow>
#include <QQmlEngine>


class MainWindow: public QQuickWindow
{
    Q_OBJECT
public:
    MainWindow(QWindow *parent = nullptr);
    ~MainWindow();

    static void registerObject(QQmlEngine* engine);

signals:
    void notify(const QString& text);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;


private:

    QObjectList        m_objects;
    static QQmlEngine* sEngine;
};

extern MainWindow* theWnd;
#endif // QUICKWINDOW_H
