#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::cout << "MainWindow::MainWindow"<<std::endl;
    this->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    std::cout << "MainWindow init"<<std::endl;
}
void MainWindow::openTabe()
{
    std::cout << "MainWindow openTabe"<<std::endl;
//    this->add
}
