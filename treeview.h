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
    explicit TreeView(MainWindow *parent);
    void iteratorOverItems();
    QList<QStandardItem *> returnTheItems();
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void selectionChanged ( const QItemSelection & selected, const QItemSelection & deselected );
    void addCollectionsMenuAction();
    void addDatabaseMenuAction();
    void focusOutEvent ( QFocusEvent * event );

signals:

public slots:
    void slotCustomContextMenu(QPoint);
    void slotMenuCustomContextMenu();
    void slotTest();
    void creationMenu();
    void destroyMenu();

private:
    QStandardItemModel *model;
    // 右键菜单
    QMenu *menu=NULL;
    MainWindow *mainWindow;
    bool isMenuDestroy = true;
    bool waitDestroy = false;
};

#endif // TREEVIEW_H
