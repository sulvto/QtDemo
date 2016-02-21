#include "treeview.h"
#include "treeviewitem.h"
#include "treeitemtype.h"
#include <QModelIndex>
#include <QDebug>
#include <QMenu>
#include <QCursor>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QColor>
#include <QPalette>
#define ROLE_MARK Qt::UserRole +1
#define ROLE_DATABASE 1
#define ROLE_COLLECTIONS 2
#define ROLE_FUNCTIONS 3
#define ROLE_USERS 4

TreeView::TreeView(MainWindow *parent) :
    QTreeView(parent)
{
    this->mainWindow = parent;
    this->setContextMenuPolicy(Qt::CustomContextMenu);

    QPalette palette;
    palette.setColor(QPalette::Base, QColor(192,192,192));
    this->setPalette(palette);
    connect(this,SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomContextMenu(QPoint)));

    model = new QStandardItemModel(4, 1);
    model->setHeaderData(0, Qt::Horizontal, "Service");

    QStandardItem *item1 = new QStandardItem("avahi-daemon");
item1->setIcon(QIcon(":/images/icons/computer.png"));
    TreeViewItem *item2 = new TreeViewItem(*parent,"bluetooth",ROLE_DATABASE);
    //TODO treeitem.h
    TreeViewItem *item3 = new TreeViewItem(*parent,"crond",ROLE_DATABASE);
    TreeViewItem *item4 = new TreeViewItem(*parent,"cups",ROLE_DATABASE);


    model->setItem(0, 0, item1);
    model->setItem(1, 0, item2->standardItem);
    model->setItem(2, 0, item3->standardItem);
    model->setItem(3, 0, item4->standardItem);

    TreeViewItem *item5 = new TreeViewItem(*parent,"fifth",ROLE_COLLECTIONS);

    item4->appendChild(item5);
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

void TreeView::selectionChanged( const QItemSelection & selected, const QItemSelection & deselected ){
    qDebug()<<"selectionChanged";
//    QTreeView::()

    destroyMenu();
}

// 鼠标双击事件(输出被双击item的文本)
void TreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QModelIndex index = currentIndex();

       this->mainWindow->openTab(index.data().toString(),index.data().toString());
        qDebug()<<index.data().toString();
    }
}

void TreeView::mousePressEvent(QMouseEvent *event){
    destroyMenu();
    QTreeView::mousePressEvent(event);
}

//右键
void TreeView::slotCustomContextMenu(QPoint p) {

    this->creationMenu();
    QModelIndex index = this->currentIndex();
//            QModelIndex index = this->indexAt(p);
    QVariant var = index.data(ROLE_MARK);
    if(var.isValid()){
        switch (var.toInt()) {
        case ROLE_DATABASE:
            addDatabaseMenuAction();
            break;
        case ROLE_FUNCTIONS:
            return;
        case ROLE_COLLECTIONS:
            addCollectionsMenuAction();
            break;
        default:
            break;
        }
    }
              qDebug()<<var.toInt();



    // 让父窗体响应鼠标事件 穿透
    this->menu->setWindowFlags(Qt::FramelessWindowHint);
    this->menu->setAttribute(Qt::WA_TranslucentBackground);

    int px = QCursor().pos().rx()-this->mainWindow->x();
    int py = QCursor().pos().ry()-this->mainWindow->y();

    this->menu->exec(QPoint(px,py-25));
}


void TreeView::addCollectionsMenuAction(){
    this->menu->addAction(QString("Collections Statistics"), this, SLOT(slotTest()));
    this->menu->addAction(QString("Create Collections"), this, SLOT(slotTest()));
    this->menu->addAction(QString("Refresh"), this, SLOT(slotTest()));
}

void TreeView::addDatabaseMenuAction(){
    this->menu->addAction(QString("Open shell"), this, SLOT(slotTest()));
    this->menu->addAction(QString("Refresh"), this, SLOT(slotTest()));
    this->menu->addAction(QString("Database Statistics"), this, SLOT(slotTest()));
    this->menu->addAction(QString("Repair Database "), this, SLOT(slotTest()));
    this->menu->addAction(QString("Drop Database "), this, SLOT(slotTest()));
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

void TreeView::creationMenu(){

//    while (this->waitDestroy) {
//        QThread::sleep(50);
//    }

//    if(!this->isMenuDestroy) {
//        this->waitDestroy = true;
//        this->menu->~QMenu();
//        this->isMenuDestroy = true;
//    }

    destroyMenu();
    this->menu = new QMenu(this->mainWindow);
    this->isMenuDestroy = false;
//    this->waitDestroy = false;
}
