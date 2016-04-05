TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    View.cpp \
    Model.cpp \
    Ball.cpp \
    GraphicElement.cpp \
    TcpClient.cpp \
    MovableElement.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    View.h \
    Model.h \
    Ball.h \
    GraphicElement.h \
    TcpClient.h \
    MovableElement.h

LIBS           += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra
