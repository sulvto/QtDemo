#include "treeviewitem.h"
#include<QStandardItem>

#define ROLE_MARK Qt::UserRole +1
#define ROLE_DATABASE 1
#define ROLE_COLLECTIONS 2
#define ROLE_FUNCTIONS 3
#define ROLE_USERS 4

TreeViewItem::TreeViewItem(MainWindow &mw,const QString &text,int itemType){
    this->standardItem = new QStandardItem(text);
    this->standardItem->setData(itemType,ROLE_MARK);
    this->mainWindow = &mw;
}

void TreeViewItem::appendChild(TreeViewItem *aitem) {
    this->child = aitem;
    this->standardItem->appendRow(aitem->standardItem);
}



