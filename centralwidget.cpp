#include "datatable.h"
#include "centralwidget.h"
#include "tabwidget.h"
#include <QMainWindow>
#include <iostream>
CentralWidget ::CentralWidget(QMainWindow *parent ){
    this->setParent(parent);
    this->tabWidget = new TabWidget();
    this->setWindowTitle("content");

    this->show();
}

