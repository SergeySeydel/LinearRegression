#include "mainwindow.h"

#include <QApplication>
#include <gradientdescent.h>
#include <stochasticgradientdescent.h>

#include <QtCharts> //Подключаем библиотеку QtCharts для отрисовки линий.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
