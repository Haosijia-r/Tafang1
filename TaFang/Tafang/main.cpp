#include "mainwindow.h"

#include <QApplication>
#include "Tafang.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    //Object window;


    window.setWindowTitle("TAFANG");
    window.show();

    return a.exec();
}
