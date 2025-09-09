#include "mainwindow.h"

#include <QApplication>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.setWindowTitle("My Chess App");
    mainWindow.show();
    return a.exec();
}

