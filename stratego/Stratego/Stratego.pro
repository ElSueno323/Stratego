TEMPLATE = subdirs

SUBDIRS += \
    Gui \
    metier \
    app #\
    Test


Test.depends = metier

OTHER_FILES += config.pri
INCLUDEPATH += images/board/


