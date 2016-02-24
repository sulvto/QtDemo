
#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QHeaderView>
#include "connectionsdialog.h"

ConnectionsDialog::ConnectionsDialog(QWidget *parent)
        : QDialog(parent)
{
    QTableView *tableView = new QTableView();

    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //准备数据模型
    QStandardItemModel *student_model = new QStandardItemModel();
    student_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Name")));
    student_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Address")));
    student_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Auth.DataBase/User")));
    student_model->setColumnCount(3);

    //设置表格的各列的宽度值
    tableView->setColumnWidth(0,170);
    tableView->setColumnWidth(1,170);
    tableView->setColumnWidth(2,170);

    tableView->setModel(student_model);

    connectButton = new QPushButton(tr("&Connect"));
    connectButton->setDefault(true);
    connectButton->setEnabled(false);

    cancelButton = new QPushButton(tr("&Cancel"));

    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(findClicked()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(connectButton);
    buttonLayout->addWidget(cancelButton);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tableView);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("MongoDB Connections"));
    setFixedHeight(400);
    setFixedWidth(510);

}

ConnectionsDialog::~ConnectionsDialog()
{

}

void ConnectionsDialog::findClicked()
{

}

void ConnectionsDialog::enableFindButton(const QString &text)
{
}
