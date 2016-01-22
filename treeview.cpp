#include "treeview.h"
#include <QModelIndex>
#include <QDebug>
#include <QMenu>
#include <QCursor>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>

TreeView::TreeView(QWidget *parent) :
    QTreeView(parent)
{
    this->parent = parent;
    this->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this,SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomContextMenu(QPoint)));

    model = new QStandardItemModel(4, 1);
    model->setHeaderData(0, Qt::Horizontal, "Service");

    QStandardItem *item1 = new QStandardItem("avahi-daemon");

    QStandardItem *item2 = new QStandardItem("bluetooth");

    QStandardItem *item3 = new QStandardItem("crond");

    QStandardItem *item4 = new QStandardItem("cups");


    model->setItem(0, 0, item1);
    model->setItem(1, 0, item2);
    model->setItem(2, 0, item3);
    model->setItem(3, 0, item4);

    QStandardItem *item5 = new QStandardItem("fifth");
    item4->appendRow(item5);
    QModelIndex myparent;
    for (int i=0; i<4; i++)
    {
        myparent = model->index(0, 0, myparent);
        model->insertRows(0, 1, myparent);  // 添加一行
        model->insertColumns(0, 1, myparent);   // 添加一列
        QModelIndex index = model->index(0, 0, myparent);
        model->setData(index, i);
    }

    this->setModel(model);

}

// 输出所有单元格的内容
void TreeView::iteratorOverItems()
{
    QList<QStandardItem *> list = this->returnTheItems();
    foreach (QStandardItem *item, list)
    {
        qDebug()<<item->text();
    }
}

// 获取所有单元格
QList<QStandardItem *> TreeView::returnTheItems()
{
    return model->findItems("*", Qt::MatchWildcard | Qt::MatchRecursive);
}

// 鼠标双击事件(输出被双击item的文本)
void TreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QModelIndex index = currentIndex();
        qDebug()<<index.data().toString();
    }
}

void TreeView::mousePressEvent(QMouseEvent *event){
    destroyMenu();
    QTreeView::mousePressEvent(event);
}

//右键
void TreeView::slotCustomContextMenu(QPoint p) {

    this->menu = new QMenu(this->parent);
    this->isMenuDestroy = false;
    QModelIndex index = this->currentIndex();
    QString fileName = this->model->data(this->model->index(index.row(), 0),0).toString();
    qDebug()<<fileName;


    this->menu->addAction(QString("Import"), this, SLOT(slotTest()));
    this->menu->addAction(QString("Export"), this, SLOT(slotTest()));
    // 让父窗体响应鼠标事件 穿透
    this->menu->setWindowFlags(Qt::FramelessWindowHint);
    this->menu->setAttribute(Qt::WA_TranslucentBackground);

    int px = QCursor().pos().rx()-this->parent->x();
    int py = QCursor().pos().ry()-this->parent->y();

    this->menu->exec(QPoint(px,py));
}

void TreeView::slotTest() {
    QModelIndex index = this->currentIndex();
    QString fileName = this->model->data(this->model->index(index.row(), 0),0).toString();
    qDebug()<<" slotTest "<<fileName;
}

void TreeView::slotMenuCustomContextMenu(){
    destroyMenu();
    qDebug()<<"slotMenuCustomContextMenu";
}

void TreeView::destroyMenu(){
    if(!this->isMenuDestroy) {
        this->menu->~QMenu();
        this->isMenuDestroy = true;
    }
}
