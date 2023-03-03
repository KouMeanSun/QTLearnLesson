#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include <QLocale>
#include <QTranslator>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setApplicationName("QT学习");
    app.setOrganizationName("GMY");

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Basic");
    engine.addImportPath(QStringLiteral("qrc:/"));
    MainWindow::registerObject(&engine);
    engine.load(QUrl(u"qrc:/Qml/main.qml"_qs));

    return app.exec();
}
