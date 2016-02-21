#include "datatable.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPalette>
#include <QStandardItemModel>
#include <QPixmap>
DataTable:: DataTable(const QString &_tableName,const QString &_content){
//    *tableName =  _tableName;
//    *content = _content;
    this->setAccessibleName(_tableName);
    QPalette palette ;
    palette.setColor(QPalette::Base, QColor(192,192,192));
    this->setPalette(palette);

    QVBoxLayout *vLayout =   new QVBoxLayout();

    QStandardItemModel *model = new QStandardItemModel;
    model->setColumnCount(2);    // 设置列数

    //设置列标题
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"NAME");
    //TODO
    model->setItem(0,0,new QStandardItem("列数"));
    QTableView  *tableView  = new QTableView();
    tableView->setModel(model);

    //列宽
//    tableView->setColumnWidth(0,60);

    //整行选择
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


    QHBoxLayout *hLayout = new QHBoxLayout();

    hLayout->addWidget(new QLabel("aaaaaaaa"));
    QLabel *lable =    new QLabel("aaaaaaaa" );
    QPixmap pix(":/images/icons/database.png");
    lable->setPixmap(pix);
    //TODO
    hLayout->addWidget(lable);
    hLayout->addWidget(new QLabel("aaaaaaaa"));

    vLayout->addLayout(hLayout);
    vLayout->addWidget(tableView);
    this->setLayout(vLayout);
}
QString DataTable::getTableName(){
    return *tableName;
}
