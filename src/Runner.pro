TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    View.cpp \
    Model.cpp \
    Ball.cpp \
    GraphicElement.cpp \
    MovableElement.cpp \
    Menu.cpp \
    SlidingBackground.cpp \
    Color.cpp \
    TU.cc \
    LogFile.cpp \
    XOR_EncryptDecryption.cpp \
    SplashText.cpp \
    Bonus.cpp \
    AnimatedGraphicElement.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    View.h \
    Model.h \
    Ball.h \
    GraphicElement.h \
    MovableElement.h \
    Menu.h \
    SlidingBackground.h \
    Color.h \
    LogFile.h \
    XOR_EncryptDecryption.h \
    SplashText.h \
    constantes.h \
    Bonus.h \
    AnimatedGraphicElement.h

LIBS           += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra

LIBS += -lboost_unit_test_framework
