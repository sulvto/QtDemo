QT += widgets

HEADERS       = mainwindow.h \
    centralwidget.h \
    datatable.h \
    tabwidget.h \
    collectionitem.h \
    treeview.h \
    databasetreeitem.h \
    treeviewitem.h \
    treeitemtype.h \
    connectionsdialog.h
SOURCES       = main.cpp \
                mainwindow.cpp \
    datatable.cpp \
    centralwidget.cpp \
    tabwidget.cpp \
    collectionitem.cpp \
    databaseitem.cpp \
    treeview.cpp \
    treeviewitem.cpp \
    connectionsdialog.cpp
#! [0]
RESOURCES     = \
    img.qrc
#! [0]

FORMS += \
    mainwindow.ui

