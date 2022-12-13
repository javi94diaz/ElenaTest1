QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Technosoft.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Technosoft.h \
    mainwindow.h \
    technosoft/inc/tmlcomm.h \
    technosoft/inc/TML_lib.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#INCLUDEPATH += $$PWD/technosoft/inc
#DEPENDPATH += $$PWD/technosoft/inc

#INCLUDEPATH += /home/multivet/sedecal/thirdparty/technosoft/inc
#DEPENDPATH += /home/multivet/sedecal/thirdparty/technosoft/inc

INCLUDEPATH += $$PWD/technosoft/inc
DEPENDPATH += $$PWD/technosoft/inc


#unix:!macx: LIBS += -L$$PWD/technosoft/lib/x86-64/ -lTML_lib
unix:!macx: LIBS += -lTML_lib
