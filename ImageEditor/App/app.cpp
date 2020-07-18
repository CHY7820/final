#include <QApplication>
#include "app.h"
using namespace std;
App::App():_MainWindow(new MainWindow)
{
    //initialize model
    _ImageModel = make_shared<ImageModel>();

    //initialize viewmodel and binding
    _ImageViewModel = make_shared<ImageViewModel>();
}

App::~App()
{
}

void App::run(){
    _ImageViewModel->SetImageModel(_ImageModel);

    //binding commands in mainwindows
    _MainWindow->BindingCommandOpen(_ImageViewModel->getOpenCommand());
    _MainWindow->BindingCommandClose(_ImageViewModel->getCloseCommand());
    _MainWindow->BindingCommandSave(_ImageViewModel->getSaveCommand());
    _MainWindow->BindingCommandRotate(_ImageViewModel->getRotateCommand());
    _MainWindow->BindingCommandGray(_ImageViewModel->getGrayCommand());
    _MainWindow->BindingCommandBlur(_ImageViewModel->getBlurCommand());
    _MainWindow->BindingCommandSharp(_ImageViewModel->getSharpCommand());
    _MainWindow->BindingCommandZoomIn(_ImageViewModel->getZoomInCommand());
    _MainWindow->BindingCommandZoomOut(_ImageViewModel->getZoomOutCommand());
    _MainWindow->BindingCommandUndo(_ImageViewModel->getUndoCommand());
    _MainWindow->setImages(_ImageViewModel->getImage());

    //add notification to viewmodel
    _ImageViewModel->AddCommandNotification(_MainWindow->getMainSink());
    _ImageViewModel->AddPropertyNotification(_MainWindow->getUpdateSink());

    //show mainwindow
    _MainWindow->show();
}
