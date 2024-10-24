QT       += core gui widgets

CONFIG += c++17
CONFIG += file_copies

DEFINES += QT_MESSAGELOGCONTEXT

TARGET = CustomWallerpaper
TEMPLATE = app

LIBS += -lUser32

SOURCES += \
    main.cpp

DESTDIR = build/release
