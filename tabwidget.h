#ifndef TABWIDGET
#define TABWIDGET
#include <QTableWidget>
#include <QString>
#include "datatable.h"
class TabWidget :public QTabWidget{

public:
    TabWidget(QWidget *parent = 0);
    void addTab(DataTable *dataTable, const QString &id,const QString &tabName);
private:
    QList<QString> *idList;
};

#endif // TABWIDGET

