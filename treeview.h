#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QTreeView>
#include <QList>
#include <QStandardItem>
#include <QMouseEvent>
#include <QtGui>
#include <QtCore>
#include <mainwindow.h>

class TreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit TreeView(QWidget *parent = 0);
    void iteratorOverItems();
    QList<QStandardItem *> returnTheItems();
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:
    void slotCustomContextMenu(QPoint);
    void slotMenuCustomContextMenu();
    void slotTest();
    void destroyMenu();

private:
    QStandardItemModel *model;
    // 右键菜单
    QMenu *menu=NULL;
    QWidget *parent;
    bool isMenuDestroy = true;
};

#endif // TREEVIEW_H
