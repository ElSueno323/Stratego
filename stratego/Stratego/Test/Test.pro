TEMPLATE = app
CONFIG -= qt
CONFIG -= app_bundle
CONFIG += console

win32-g++*{

    QMAKE_CXXFLAGS += -Wa,-mbig-obj

}
include ("../config.pri")

INCLUDEPATH += $$PWD/../metier
DEPENDPATH += $$PWD/../metier

isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR=$$(CATCH_INCLUDE_DIR)
# set by Qt Creator wizard
isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR="../libs/"
!isEmpty(CATCH_INCLUDE_DIR): INCLUDEPATH *= $${CATCH_INCLUDE_DIR}

isEmpty(CATCH_INCLUDE_DIR): {
    message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
}

SOURCES +=     main.cpp     tst_model.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../metier/release/ -lmetier
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../metier/debug/ -lmetier
else:unix: LIBS += -L$$OUT_PWD/../metier/ -lmetier

INCLUDEPATH += $$PWD/../metier
DEPENDPATH += $$PWD/../metier

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../metier/release/libmetier.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../metier/debug/libmetier.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../metier/release/metier.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../metier/debug/metier.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../metier/libmetier.a
