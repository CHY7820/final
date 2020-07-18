#ifndef UPDATESINK_H
#define UPDATESINK_H


#include "../../Common/notification.h"
#include "../../View/mainwindow.h"

class MainWindow;
class UpdateSink: public IPropertyNotification
{
public:
    UpdateSink(MainWindow *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
   MainWindow * _Update;
};

#endif // UPDATESINK_H
