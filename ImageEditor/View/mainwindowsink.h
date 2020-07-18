#ifndef MAINWINDOWSINK_H
#define MAINWINDOWSINK_H
#include "mainwindow.h"
#include "../Common/notification.h"
using namespace std;
class MainWindow;
class mainwindowsink:public ICommandNotification
{
public:
    mainwindowsink(MainWindow* ptr);
    virtual void OnCommandComplete(const string& str, bool is) override;
private:
     MainWindow * _mainwindow;

};

#endif // MAINWINDOWSINK_H
