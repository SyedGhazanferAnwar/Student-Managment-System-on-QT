#-------------------------------------------------
#
# Project created by QtCreator 2017-04-30T12:49:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FINALCP_PROJECT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp\
        admin.cpp\
        cppperson.cpp\
        login.cpp\
        customshadoweffect.cpp\
        cppteacher.cpp\
        cppstudent.cpp \
    marks.cpp \
    teacher_access.cpp \
    global.cpp \
    teacher_acess_n.cpp\
    student.cpp

HEADERS  += mainwindow.h\
           admin.h\
           cppperson.h\
           login.h\
           customshadoweffect.h\
           cppteacher.h\
           cppstudent.h \
    marks.h \
    teacher_access.h \
    global.h \
    teacher_acess_n.h\
    student.h

FORMS    += mainwindow.ui\
            admin.ui\
            login.ui \
    teacher_access.ui \
    teacher_acess_n.ui\
    student.ui
RESOURCES += \
    image.qrc\
    res.qrc
