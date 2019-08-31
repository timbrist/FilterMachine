#include "mainwindow.h"
#include <QApplication>

#include <QLabel>
#include <QPixmap>
#include <QImage>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


   return a.exec();

}
