#ifndef IMAGEMODELSINK_H
#define IMAGEMODELSINK_H
#include "../../Common/notification.h"
class ImageViewModel;
class ImageModelSink: public IPropertyNotification
{
public:
    ImageModelSink(ImageViewModel* ptr);
    virtual void OnPropertyChanged(const std::string &str) override;
private:
    ImageViewModel* _ImageVM;
};

#endif // IMAGEMODELSINK_H
