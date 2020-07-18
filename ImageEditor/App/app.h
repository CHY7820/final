#ifndef APP_H
#define APP_H
#include <iostream>
#include <QApplication>
#include "./View/mainwindow.h"
#include "./Model/imagemodel.h"
#include "./ViewModel/imageviewmodel.h"

using namespace std;
class App
    {
    private:
        MainWindow* _MainWindow;
        shared_ptr<ImageModel> _ImageModel;
        shared_ptr<ImageViewModel> _ImageViewModel;

    public:
        App();
        ~App();
        void run();
        MainWindow* getMainWindow();
    };

#endif // APP_H

