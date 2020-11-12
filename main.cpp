#include "mainwindow.h"

#include <QApplication>
#include "viewelement.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  // MainWindow w;
  //  w.show();

    viewElement v;
    v.show();
    return a.exec();
}
