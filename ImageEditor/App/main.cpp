#include "View/mainwindow.h"
#include "App/app.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App ImageProcessor;
    ImageProcessor.run();
    return a.exec();
}
