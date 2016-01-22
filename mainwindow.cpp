
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QSplitter>
#include <QBoxLayout>
#include <QObject>
#include <QTextEdit>
#include <QTreeWidget>
#include <QTreeView>
#include <QTreeWidgetItem>
#include <treeview.h>
#include "qnamespace.h"
#include "mainwindow.h"
#include "centralwidget.h"
#include "datatable.h"
#include "tabwidget.h"
#include "databasetreeitem.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::cout << "MainWindow::MainWindow"<<std::endl;
    this->init();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::init() {
    this->initTab();
    this->initToolMenus();


    TabWidget *tabWidget = new TabWidget(this);
    DataTable *dataTable1 = new DataTable(QString("aaa"),QString("bbb"));
    DataTable *dataTable2 = new DataTable(QString("aaa"),QString("bbb"));
    tabWidget->addTab(dataTable1,"Table name1");
    tabWidget->addTab(dataTable2,"Table name2");

    TreeView *treeView = new TreeView(this);

    QSplitter    *mainSplitter = new QSplitter(this);
    mainSplitter->addWidget(treeView);
    mainSplitter->addWidget(tabWidget );
    mainSplitter->setStretchFactor(1, 1);
    this->setCentralWidget(mainSplitter);
    std::cout << "MainWindow init"<<std::endl;
}

void MainWindow::initTab() {
    //    this->addDockWidget(centralWidget);
    std::cout << "MainWindow initTab"<<std::endl;
}

void MainWindow::showConnectionsPanel() {
    std::cout << "MainWindow showConnectionsPanel"<<std::endl;
}
void MainWindow::openTab() {
    std::cout << "MainWindow openTabe"<<std::endl;
}

void MainWindow::initToolMenus(){
    QAction *connectionsAction = new QAction(tr("Connections"), this);
    connect(connectionsAction, SIGNAL(triggered()), this, SLOT(showConnectionsPanel()));

    QAction *openAction = new QAction(tr("Open"), this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openTab()));

    QMenu *fileMenu = new  QMenu ("File",this);
    fileMenu->addAction(connectionsAction);
    fileMenu->addAction(openAction);
    menuBar()->addMenu(fileMenu);

    QMenu *helpMenu = new  QMenu ("Help",this);
    menuBar()->addMenu(helpMenu);

    std::cout << "MainWindow initToolMenus"<<std::endl;
}
