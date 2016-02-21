#ifndef TREEITEM
#define TREEITEM
#include <QStandardItem>
#include "mainwindow.h"
#include "treeitemtype.h"

class TreeViewItem {

public:
    explicit TreeViewItem(MainWindow &mainWindow,const  QString &text,int itemType);
    void appendChild(TreeViewItem *aitem) ;
    QStandardItem *standardItem;


private:
    MainWindow *mainWindow;
    TreeItemType type;
    TreeViewItem *child;

};
#endif // TREEITEM

