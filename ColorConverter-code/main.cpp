
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(612, 804);
    w.setWindowTitle("Color converter");
    w.show();
    return a.exec();
}
