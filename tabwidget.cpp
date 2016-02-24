#include "tabwidget.h"
#include "datatable.h"
#include <QTabWidget>
#include <QDebug>
#include <iostream>

TabWidget::TabWidget(QWidget *parent){
    this->setParent(parent);
    this->setAccessibleName("welcome");
    this->setTabsClosable(true);
    this->idList = new QList<QString>();
}

void TabWidget::addTab(DataTable *dataTable, const QString &id, const QString &tabName){
    std::cout << "TabWidget addTab"<<std::endl;
//    std::cout << this->idList->size()<<std::endl;

//    if(this->idList->lastIndexOf(id)<0){
//        this->idList->append(id);
        QTabWidget::addTab(dataTable,tabName);
//    }
}

void TabWidget::focusInEvent ( QFocusEvent * event ){
    qDebug()<<"TabWidget focusInEvent";
}


