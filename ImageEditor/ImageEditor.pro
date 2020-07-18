QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    App/app.cpp \
    App/main.cpp \
   # Common/utils.cpp \
    Model/imagemodel.cpp \
    Model/utils.cpp \
    View/mainwindow.cpp \
    View/mainwindowsink.cpp \
    View/tabpage.cpp \
    ViewModel/ImageViewModel.cpp \
    ViewModel/command/BasicCommands.cpp \
    ViewModel/command/FilterCommands.cpp \
    ViewModel/sink/ImageModelSink.cpp \
    ViewModel/sink/updatesink.cpp

HEADERS += \
    App/app.h \
    Common/Parameter.h \
    Common/notification.h \
   # Common/image.h \
   # Common/utils.h \
    Model/utils.h \
    Model/imagemodel.h \
    View/mainwindow.h \
    View/mainwindowsink.h \
    View/tabpage.h \
    ViewModel/ImageViewModel.h \
    ViewModel/command/BasicCommands.h \
    ViewModel/command/FilterCommands.h \
    ViewModel/sink/ImageModelSink.h \
    ViewModel/sink/updatesink.h \

FORMS += \
    View/mainwindow.ui \
    View/tabpage.ui

INCLUDEPATH += \
$$PWD/Common/opencv/include \

LIBS += $$PWD/Common/opencv/lib/libopencv_*.a

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RC_FILE = Asset/Icon/win.rc

RESOURCES += \
    Asset/Resource.qrc
