#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T16:40:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HeartFEniCSUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    projectpreferencesdialog.cpp \
    preferencesdialog.cpp \
    Data/guiconfigdata.cpp \
    Data/vol4dconfigurationdata.cpp \
    Data/matlabconfigurationdata.cpp \
    Data/ansaconfigurationdata.cpp \
    XML/guiconfigdataxmlparser.cpp \
    Data/inflowoutflowdatamark.cpp \
    Data/simulationconfigurationdata.cpp \
    clinicaldatagenerationdialog.cpp \
    manualpatientnumberingdialog.cpp \
    Data/patientdata.cpp \
    Data/projectdata.cpp \
    XML/projectdataxmlparser.cpp \
    specificloadingrulesdialog.cpp \
    TXT/listclinicalwriter.cpp \
    removepatientsdialog.cpp \
    Parser/scriptparser.cpp \
    Data/clusterdata.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    projectpreferencesdialog.h \
    preferencesdialog.h \
    Data/guiconfigdata.h \
    Data/vol4dconfigurationdata.h \
    Data/matlabconfigurationdata.h \
    Data/ansaconfigurationdata.h \
    XML/guiconfigdataxmlparser.h \
    Defines/XmlDefines.h \
    Data/inflowoutflowdatamark.h \
    Data/simulationconfigurationdata.h \
    clinicaldatagenerationdialog.h \
    manualpatientnumberingdialog.h \
    Data/patientdata.h \
    Data/projectdata.h \
    XML/projectdataxmlparser.h \
    specificloadingrulesdialog.h \
    TXT/listclinicalwriter.h \
    removepatientsdialog.h \
    Parser/scriptparser.h \
    Data/clusterdata.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    projectpreferencesdialog.ui \
    preferencesdialog.ui \
    clinicaldatagenerationdialog.ui \
    manualpatientnumberingdialog.ui \
    specificloadingrulesdialog.ui \
    removepatientsdialog.ui \
    aboutdialog.ui

RESOURCES += \
    resourcesUI.qrc
