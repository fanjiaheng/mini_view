#-------------------------------------------------
#
# Project created by QtCreator 2020-06-06T11:07:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniView
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
        main.cpp \
    MainWindow.cpp \
    MainView.cpp \
    MainMenu.cpp \
    MiniView.cpp \
    VideoSetting.cpp \
    CameraSetting.cpp \
    NetSetting.cpp \
    SystemSetting.cpp

HEADERS += \
    MainWindow.h \
    MainView.h \
    MainMenu.h \
    MiniView.h \
    VideoSetting.h \
    CameraSetting.h \
    NetSetting.h \
    SystemSetting.h

FORMS += \
    MainView.ui \
    MainMenu.ui \
    MainWindow.ui \
    VideoSetting.ui \
    CameraSetting.ui \
    NetSetting.ui \
    SystemSetting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

