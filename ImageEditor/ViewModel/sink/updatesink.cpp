#include "updatesink.h"
#include "../../View/mainwindow.h"

UpdateSink::UpdateSink(MainWindow *ptr)
{
    _Update = ptr;
}

 void UpdateSink::OnPropertyChanged(const std::string& str){
    if(str=="ImageModel"){
        _Update->update();
    }

}
