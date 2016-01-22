#ifndef CENTRALWIDGET
#define CENTRALWIDGET
#include <QWidget>
#include <QTabWidget>
#include <QMainWindow>
#include "datatable.h"
class CentralWidget:public QWidget{

public:
    CentralWidget(QMainWindow *parent);


private:
    QTabWidget *tabWidget;

};

#endif // CENTRALWIDGET

