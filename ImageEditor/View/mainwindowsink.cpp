#include "mainwindowsink.h"

mainwindowsink::mainwindowsink(MainWindow *ptr)
{
    _mainwindow = ptr;
}

void mainwindowsink::OnCommandComplete(const std::string& str, bool is)
{
    if(str=="GrayCommand"){
        if(is==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("Error!"));
            MSG.exec();
        }
    }
    else if(str=="BlurCommand"){
        if(is==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("Error!"));
            MSG.setText(QString("Delete failed! \n Array is empty or the number is not in Array"));
            MSG.exec();
        }
    }
    else if(str=="SharpCommand"){
        if(is==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("Error!"));
            MSG.exec();
        }
    }
    else if(str=="RotateCommand"){
        if(!is){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("Error!"));
            MSG.exec();
        }
    }

}
