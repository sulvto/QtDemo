
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


    tabWidget = new TabWidget(this);
    connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(removeTab(int)));


    TreeView *treeView = new TreeView(this);
//
//
    QSplitter *mainSplitter = new QSplitter(Qt::Vertical,this);
    QSplitter *secondSplitter = new QSplitter(this);
    QSplitter *primarySplitter = new QSplitter(Qt::Horizontal,this);
    treeView->setFixedWidth(150);
    primarySplitter->addWidget(treeView);
    primarySplitter->addWidget(tabWidget);

    QTextEdit *textEdit = new QTextEdit(QString("Logs"),secondSplitter);

    textEdit->setText(QString("aaa"));
    textEdit->setHtml("aaaaaaaaaaaaa");
    secondSplitter->addWidget(textEdit);
    mainSplitter->addWidget(primarySplitter);
    mainSplitter->addWidget(secondSplitter);
    mainSplitter->setStretchFactor(0, 65);
    mainSplitter->setStretchFactor(1, 35);

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

void MainWindow::openTab(const QString &tabId, const QString &tabName) {
    DataTable *dataTable = new DataTable(QString("aaa"),QString("bbb"));
    tabWidget->addTab(dataTable,tabId,tabName);
    std::cout << "MainWindow openTabe"<<std::endl;
}

void MainWindow::initToolMenus(){

    addFileMenu();
    addViewMenu();
    addOptionsMenu();
//    addWindowMenu();
    addHelpMenu();

    std::cout << "MainWindow initToolMenus"<<std::endl;
}

void MainWindow::addFileMenu(){
    QAction *connectionsAction = new QAction(tr("Connections"), this);
    connectionsAction->setShortcut(tr("Ctrl+N"));
    connect(connectionsAction, SIGNAL(triggered()), this, SLOT(showConnectionsPanel()));
    QAction *separatorAction1 = new QAction(tr(""), this);
    separatorAction1 ->setSeparator(true);

    QAction *openAction = new QAction(tr("Open"), this);
    openAction->setShortcut(tr("Ctrl+O"));

    // TODO
    connect(openAction, SIGNAL(triggered()), this, SLOT(openTab()));
    QAction *saveAction = new QAction(tr("Save"), this);
    saveAction->setShortcut(tr("Ctrl+S"));

    QAction *saveAsAction = new QAction(tr("Save As"), this);
    saveAsAction->setShortcut(tr("Ctrl+S"));

    QAction *separatorAction2 = new QAction(tr(""), this);
    separatorAction2 ->setSeparator(true);

    QAction *exitAction = new QAction(tr("Exit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));


    QMenu *fileMenu = new  QMenu ("File",this);
    fileMenu->addAction(connectionsAction);
    fileMenu->addAction(separatorAction1);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addAction(separatorAction2);
    fileMenu->addAction(exitAction);

    menuBar()->addMenu(fileMenu);
}
void MainWindow::addViewMenu(){
    QMenu *viewMenu = new  QMenu ("View",this);

    QAction *explorerAction = new QAction(tr("Explorer"), this);
    explorerAction->setShortcut(tr("Ctrl+E"));

    QAction *logsAction = new QAction(tr("Logs"), this);
    logsAction->setShortcut(tr("Ctrl+L"));

    QMenu *toolbarsMenu = new QMenu(tr("Toolbars"), this);
    QAction *connectionsToolbar= new QAction(tr("Connections Toolbar"), this);
    QAction *openOrSaveToolbar= new QAction(tr("Open/Save Toolbar"), this);
    QAction *executionToolbar= new QAction(tr("Execution Toolbar"), this);
    toolbarsMenu->addAction(connectionsToolbar);
    toolbarsMenu->addAction(openOrSaveToolbar);
    toolbarsMenu->addAction(executionToolbar);

    QAction *separatorAction = new QAction(tr(""), this);
    separatorAction ->setSeparator(true);

    QMenu *themeMenu = new QMenu(tr("Theme"), this);
    QAction *nativeTheme  = new QAction(tr("Native"), this);
    QAction *windowTheme = new QAction(tr("Window"), this);
    QAction *gtkTheme  = new QAction(tr("GTK+"), this);

    themeMenu->addAction(nativeTheme);
    themeMenu->addAction(windowTheme);
    themeMenu->addAction(gtkTheme  );

    viewMenu->addAction(explorerAction );
    viewMenu->addAction(logsAction );
    viewMenu->addMenu(toolbarsMenu );
    viewMenu->addAction(separatorAction );
    viewMenu->addMenu(themeMenu );

    menuBar()->addMenu(viewMenu );

}

void MainWindow::addOptionsMenu(){

    QMenu *optionsMenu = new  QMenu ("Options",this);
    QMenu *setViewModeAction = new QMenu(tr("Default View Mode"), this);


    QAction *treeMode  = new QAction(tr("Tree Mode"), this);
    treeMode->setShortcut(tr("F2"));
    QAction *tableMode = new QAction(tr("Table Mode"), this);
    tableMode->setShortcut(tr("F3"));
    QAction *textMode = new QAction(tr("Text Mode"), this);
    textMode->setShortcut(tr("F4"));

    setViewModeAction->addAction(treeMode);
    setViewModeAction->addAction(tableMode);
    setViewModeAction->addAction(textMode);
    optionsMenu->addMenu(setViewModeAction);
    menuBar()->addMenu(optionsMenu );

}

void MainWindow::addWindowMenu(){

    QMenu *windowMenu = new  QMenu ("Window",this);

    menuBar()->addMenu(windowMenu );
}

void MainWindow::addHelpMenu(){
    QMenu *helpMenu = new  QMenu ("Help",this);
    QAction *aboutAction = new QAction(tr("About"), this);
    helpMenu->addAction(aboutAction );
    menuBar()->addMenu(helpMenu);

}
void MainWindow::removeTab(int index){
    std::cout << "MainWindow removeTab"<<std::endl;
    this->tabWidget->removeTab(index);
    std::cout <<index<<std::endl;

}
