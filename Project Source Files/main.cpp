#include "mainwindow.h"
#include <QApplication>
#include<admin.h>
#include<login.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
  // w.adjustSize();
    w.show();

    return a.exec();
}
