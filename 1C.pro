TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Counterparty.cpp \
        Product.cpp \
        Purchase_Invoice.cpp \
        Sale_Invoice.cpp \
        functions.cpp \
        main.cpp

HEADERS += \
    Counterparty.h \
    General_Documents.h \
    Includes.h \
    Product.h \
    Purchase_Invoice.h \
    Sale_Invoice.h
