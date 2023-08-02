QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=gnu++23
QMAKE_CXXFLAGS += -Os
QMAKE_CXXFLAGS += -ftemplate-depth=131072
QMAKE_CXXFLAGS += -ftemplate-backtrace-limit=0
QMAKE_CXXFLAGS += -fconcepts-diagnostics-depth=2048
QMAKE_CXXFLAGS += -fconstexpr-loop-limit=100000000
QMAKE_CXXFLAGS += -s
QMAKE_CXXFLAGS += -m64

CONFIG += c++latest
CONFIG += release
CONFIG += autogen_precompile_source
CONFIG += precompile_header

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
# disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += c:/msys64/mingw64/include \
               c:/msys64/mingw64/include/c++/13.1.0 \
               c:/msys64/mingw64/include/boost

LIBS += -L c:/msys64/mingw64/lib -lstdc++

SOURCES += \
    ../src/digit_variant_t.cpp \
    ../src/memory_handler.cpp \
    GUITypesNHelpers.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../include/auxiliary_functions.hpp \
    ../include/auxiliary_types.hpp \
    ../include/basic_types.hpp \
    ../include/dig_t.hpp \
    ../include/digit_variant_t.hpp \
    ../include/memory_handler.hpp \
    ../include/utilities.hpp \
    ../include/varlist_definitions.hpp \
    GUITypesNHelpers.hpp \
    mainwindow.hpp

FORMS += \
    mainwindow.ui

#TRANSLATIONS += \
#    NumReprGUI_es_ES.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
