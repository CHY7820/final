#ifndef IMAGEVIEWMODEL_H
#define IMAGEVIEWMODEL_H

#include<QImage>
#include "../Model/imagemodel.h"
#include "../Model/utils.h"
#include "../Common/notification.h"
#include "sink/ImageModelSink.h"
#include "command/FilterCommands.h"
#include "command/BasicCommands.h"


using namespace std; 

class ImageViewModel:public Proxy_PropertyNotification<ImageViewModel>,
        public Proxy_CommandNotification<ImageViewModel>
{
public:
    ImageViewModel();
    ~ImageViewModel(){}

    void SetImageModel(const std::shared_ptr<ImageModel> &ImageM);

    QList<shared_ptr<QImage>>* getImage();

    shared_ptr<ICommandBase> getOpenCommand();
    shared_ptr<ICommandBase> getCloseCommand();
    shared_ptr<ICommandBase> getSaveCommand();
    shared_ptr<ICommandBase> getSaveAsCommand();
    shared_ptr<ICommandBase> getGrayCommand();
    shared_ptr<ICommandBase> getBlurCommand();
    shared_ptr<ICommandBase> getSharpCommand();
    shared_ptr<ICommandBase> getZoomInCommand();
    shared_ptr<ICommandBase> getZoomOutCommand();
    shared_ptr<ICommandBase> getRotateCommand();
    shared_ptr<ICommandBase> getUndoCommand();

    void execOpenCommand(const QString &path,int id);
    void execCloseCommand(int id);
    void execSaveCommand(const QString &path,int id);
    void execGrayCommand(int id);
    void execBlurCommand(int ksize, int anchor,int id);
    void execSharpCommand(int id);
    void execZoomInCommand(int id);
    void execZoomOutCommand(int id);
    void execRotateCommand(int angle,int id);
    void execUndoCommand(const QImage &img,int id);

    void setCurrentId(int id);
    int getCurrentId(int id);
    void update();

private:
    shared_ptr<ImageModelSink> _ImageMS;

    QList<std::shared_ptr<QImage>> images;

    shared_ptr<ImageCommandGray> _Gray;
    shared_ptr<ImageCommandSharp> _Sharp;
    shared_ptr<ImageCommandBlur> _Blur;
    shared_ptr<ImageCommandOpen> _Open;
    shared_ptr<ImageCommandClose> _Close;
    shared_ptr<ImageCommandSave> _Save;
    shared_ptr<ImageCommandZoomIn> _ZoomIn;
    shared_ptr<ImageCommandZoomOut> _ZoomOut;
    shared_ptr<ImageCommandRotate> _Rotate;
    shared_ptr<ImageModel> _ImageModel;
    shared_ptr<ImageCommandUndo> _Undo;

};
#endif // IMAGEVIEWMODEL_H
