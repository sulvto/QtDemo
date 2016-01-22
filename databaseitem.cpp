#include "databasetreeitem.h"
#include <QTreeWidget>
#include <QString>
#include <QtDebug>
#include <QMouseEvent>
#include <QMenu>

DataBaseTreeItem::DataBaseTreeItem(QWidget *parent)
    :QTreeView(parent) {
    this->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this,SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomContextMenu(QPoint)));

}

// 鼠标双击事件(输出被双击item的文本)
void DataBaseTreeItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QModelIndex index = currentIndex();
        qDebug()<<index.data().toString();
    }
}

//右键
void DataBaseTreeItem::slotCustomContextMenu(QPoint)
{

QMenu *menu = new QMenu;
QModelIndex index = this->currentIndex();

 QString fileName = this->model->data(this->model->index(index.row(), 0),0).toString();
 qDebug()<<fileName;

 menu->addAction(QString("Import"), this, SLOT(slotTest()));
 menu->addAction(QString("Export"), this, SLOT(slotTest()));
 menu->exec(QCursor::pos());
}

