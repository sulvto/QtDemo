#ifndef COLLECTIONITEM
#define COLLECTIONITEM
#include <QString>
#include <QWidget>
#include <QTreeView>
#include <QStandardItem>

class CollectionTreeItem:public QTreeView{
    Q_OBJECT
public:
    explicit CollectionTreeItem(QWidget *parent = 0);
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:

public slots:
    void slotCustomContextMenu(QPoint);

private:
    QStandardItemModel *model;
};
#endif // COLLECTIONITEM

