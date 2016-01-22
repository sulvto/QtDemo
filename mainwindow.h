#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
      void init();
      void initTab();
      void openTab();
      void showConnectionsPanel();



private:
    Ui::MainWindow *ui;
    void initToolMenus();
};

#endif // MAINWINDOW_H
