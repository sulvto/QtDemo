#include "tabwidget.h"
#include "datatable.h"
#include <QTabWidget>
#include <iostream>

TabWidget::TabWidget(QWidget *parent){
    this->setParent(parent);
    this->setAccessibleName("welcome");
    this->setTabsClosable(true);
}
void TabWidget::addTab(DataTable *dataTable, const QString &tabName){
    std::cout << "TabWidget addTab"<<std::endl;
    QTabWidget::addTab(dataTable,tabName);
}
