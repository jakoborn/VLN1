QT += core
QT -= gui

CONFIG += c++11

TARGET = Skil1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    servicelayer.cpp \
    datalayer.cpp

HEADERS += \
    consoleui.h \
    servicelayer.h \
    datalayer.h
