QT       += core gui widgets opengl openglwidgets quick quickcontrols2 multimedia network core5compat xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    MyListModel.cpp \
    QQuickPaintedItem/ImageProvider.cpp \
    QQuickPaintedItem/XImageView.cpp \
    ShowImage.cpp \
    main.cpp

HEADERS += \
    MainWindow.h \
    MyListModel.h \
    QQuickPaintedItem/ImageProvider.h \
    QQuickPaintedItem/XImageView.h \
    ShowImage.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    qml.qrc \
    res.qrc
