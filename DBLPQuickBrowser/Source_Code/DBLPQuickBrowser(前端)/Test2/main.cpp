#include "mainwindow.h"
#include "commonhelper.h"
#include <QApplication>
#include <QFile>
#include <QTextCodec>

int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);
    MainWindow w;
    CommonHelper::setStyle("G:\\dblp\\second.qss");
    w.show();
    return a.exec();
}
