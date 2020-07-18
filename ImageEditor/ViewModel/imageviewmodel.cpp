#include "imageviewmodel.h"
#include "sink/ImageModelSink.h"
#include <iostream>

using namespace std;

ImageViewModel::ImageViewModel()
{
    _ImageMS = std::make_shared<ImageModelSink>(this);
    images.push_back(make_shared<QImage>());
    _Open = std::make_shared<ImageCommandOpen>(this);
    _Close = std::make_shared<ImageCommandClose>(this);
    _Save = std::make_shared<ImageCommandSave>(this);
    _Rotate = std::make_shared<ImageCommandRotate>(this);
    _Gray = std::make_shared<ImageCommandGray>(this);
    _Blur = std::make_shared<ImageCommandBlur>(this);
    _Sharp = std::make_shared<ImageCommandSharp>(this);
    _ZoomIn = std::make_shared<ImageCommandZoomIn>(this);
    _ZoomOut = std::make_shared<ImageCommandZoomOut>(this);
     _Undo = std::make_shared<ImageCommandUndo>(this);
}

void ImageViewModel::update()
{
    int id = _ImageModel->GetCurrentId();
    *(images.at(id)) = Mat2QImage(*_ImageModel->getImage(id));
}

QList<std::shared_ptr<QImage>>* ImageViewModel::getImage()
{
    return &images;
}

//void ImageViewModel::setCurrentId(int id)
//{
//    _ImageModel->SetCurrentId(id);
//}

int ImageViewModel::getCurrentId(int id)
{
   return id;
}

void ImageViewModel::SetImageModel(const std::shared_ptr<ImageModel> &_ImageM){
    _ImageModel = _ImageM;
    _ImageModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(_ImageMS));
}

std::shared_ptr<ICommandBase> ImageViewModel::getGrayCommand(){
    return std::static_pointer_cast<ICommandBase>(_Gray);
}

std::shared_ptr<ICommandBase> ImageViewModel::getBlurCommand(){
    return std::static_pointer_cast<ICommandBase>(_Blur);
}

std::shared_ptr<ICommandBase> ImageViewModel::getSharpCommand(){
    return std::static_pointer_cast<ICommandBase>(_Sharp);
}

shared_ptr<ICommandBase> ImageViewModel::getZoomInCommand()
{
    return std::static_pointer_cast<ICommandBase>(_ZoomIn);
}

shared_ptr<ICommandBase> ImageViewModel::getZoomOutCommand()
{
    return std::static_pointer_cast<ICommandBase>(_ZoomOut);
}

shared_ptr<ICommandBase> ImageViewModel::getUndoCommand()
{
    return _Undo;
}
std::shared_ptr<ICommandBase> ImageViewModel::getOpenCommand()
{
    return std::static_pointer_cast<ICommandBase>(_Open);  //上行转换 父类ICommandBase控制
}

std::shared_ptr<ICommandBase> ImageViewModel::getCloseCommand()
{
    return std::static_pointer_cast<ICommandBase>(_Close);
}

std::shared_ptr<ICommandBase> ImageViewModel::getSaveCommand()
{
    return std::static_pointer_cast<ICommandBase>(_Save);
}

std::shared_ptr<ICommandBase> ImageViewModel::getRotateCommand()
{
    return std::static_pointer_cast<ICommandBase>(_Rotate);
}

void ImageViewModel::execOpenCommand(const QString &path,int id)
{
    images.push_back(make_shared<QImage>());
    _ImageModel->Open(path,id);
}

void ImageViewModel::execCloseCommand(int id)
{
    images.removeAt(id);
    _ImageModel->Close(id);
}

void ImageViewModel::execSaveCommand(const QString &path,int id)
{
    _ImageModel->Save(path,id);
}

void ImageViewModel::execGrayCommand(int id)
{
    _ImageModel->Gray(id);
}

void ImageViewModel::execBlurCommand(int ksize, int anchor,int id)
{
    _ImageModel->Blur(ksize, anchor,id);
}

void ImageViewModel::execSharpCommand(int id)
{
    _ImageModel->Sharp(id);
}

void ImageViewModel::execZoomInCommand(int id)
{
    _ImageModel->ZoomIn(id);
}

void ImageViewModel::execZoomOutCommand(int id)
{
    _ImageModel->ZoomOut(id);
}

void ImageViewModel::execRotateCommand(int angle,int id)
{
    _ImageModel->Rotate(angle,id);
}

void ImageViewModel::execUndoCommand(const QImage &img,int id)
{
//    *images.at(id) = img;
    _ImageModel->setMat(QImage2Mat(img),id);
}



