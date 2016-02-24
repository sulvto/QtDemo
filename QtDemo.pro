QT += widgets

HEADERS       = mainwindow.h \
    centralwidget.h \
    datatable.h \
    tabwidget.h \
    collectionitem.h \
    treeview.h \
    databasetreeitem.h \
    treeviewitem.h \
    treeitemtype.h
SOURCES       = main.cpp \
                mainwindow.cpp \
    datatable.cpp \
    centralwidget.cpp \
    tabwidget.cpp \
    collectionitem.cpp \
    databaseitem.cpp \
    treeview.cpp \
    treeviewitem.cpp
#! [0]
RESOURCES     = \
    img.qrc
#! [0]

FORMS += \
    mainwindow.ui

