TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Cliente/cliente.cpp \
    Interface/interface.cpp \
    Item/estoque.cpp \
    Item/item.cpp \
    Item/itembase.cpp \
    Item/itemencantado.cpp \
    Item/itemfinal.cpp \
    Sistema/observer.cpp \
    Sistema/sistema.cpp \
    Sistema/subject.cpp \
    Sistema/vendaitemfinal.cpp

HEADERS += \
    Cliente/cliente.h \
    Interface/interface.h \
    Item/estoque.h \
    Item/item.h \
    Item/itembase.h \
    Item/itemencantado.h \
    Item/itemfinal.h \
    Sistema/observer.h \
    Sistema/sistema.h \
    Sistema/subject.h \
    Sistema/vendaitemfinal.h

