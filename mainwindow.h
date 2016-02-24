#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tabwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addFileMenu();
    void addViewMenu();
    void addOptionsMenu();
    void addWindowMenu();
    void addHelpMenu();

public slots:
      void init();
      void initTab();
      void openTab(const QString &tabId, const QString &tabName);
      void showConnectionsPanel();
      void removeTab(int index);
      void slotCustomContextMenu(QPoint);


private:
    Ui::MainWindow *ui;
    void initToolMenus();
    TabWidget *tabWidget;
};

#endif // MAINWINDOW_H
