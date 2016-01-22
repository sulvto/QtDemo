
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
//    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    app.setOrganizationName("QtProject");
    app.setApplicationName("Application Example");
    MainWindow mainWin;
    mainWin.setFixedSize(800,500);
    mainWin.show();
    return app.exec();
}
