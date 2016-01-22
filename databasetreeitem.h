#ifndef DATABASEITEM
#define DATABASEITEM
#include <QTreeWidget>
#include <QStandardItem>

class DataBaseTreeItem: public QTreeView
{
    Q_OBJECT
public:
    explicit DataBaseTreeItem(QWidget *parent = 0);
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:

public slots:
    void slotCustomContextMenu(QPoint);

private:
    QStandardItemModel *model;
};
#endif // DATABASEITEM

