# ------------------------------------------------
# Project created by QtCreator 2010-01-31T16:45:48
# ------------------------------------------------

QT -= gui

TARGET = Jaytrace

CONFIG += debug
CONFIG += console
CONFIG -= app_bundle
CONFIG += qtestlib

TEMPLATE = app

INCLUDEPATH += /usr/include/eigen2

SOURCES += main.cpp \
	Ray.cpp \
	tests/RayTest.cpp
HEADERS += Ray.h \
	tests/RayTest.h
