TEMPLATE = lib
TARGET = metier
CONFIG += staticlib

include("../config.pri")

SOURCES += \
    board.cpp \
    case.cpp \
    entity.cpp \
    game.cpp \
    mapreader.cpp \
    position.cpp

HEADERS += \
    ROLE.h \
    STATE.h \
    board.h \
    case.h \
    entity.h \
    game.h \
    mapreader.h \
    observable.h \
    observer.h \
    position.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.pri
