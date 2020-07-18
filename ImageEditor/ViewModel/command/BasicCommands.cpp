#include "../../ViewModel/command/BasicCommands.h"
#include "ViewModel/imageviewmodel.h"
#include <QString>

ImageCommandOpen::ImageCommandOpen(ImageViewModel* ptr)
 {
     _ImageVM= ptr;
 }
void ImageCommandOpen::SetParameter(std::shared_ptr<Parameters> param)
{
    this->path = static_pointer_cast<pathParameters>(param)->getPath();
}

void ImageCommandOpen::Exec(int id)
{
    _ImageVM->execOpenCommand(path,id);
    _ImageVM->Fire_OnCommandComplete("Open", true);
}

/*void ImageCommandOpen::Exec(int id)
{
    _ImageVM->execOpenCommand(path,id);
    _ImageVM->Fire_OnCommandComplete("Open", true);
}*/
//-----------------------------
ImageCommandClose::ImageCommandClose(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}

void ImageCommandClose::SetParameter(std::shared_ptr<Parameters> param){}


void ImageCommandClose::Exec(int id)
{
    _ImageVM->execCloseCommand(id);
    _ImageVM->Fire_OnCommandComplete("Close",true);
}
/*void ImageCommandClose::Exec(int id)
{
    _ImageVM->execCloseCommand(id);
    _ImageVM->Fire_OnCommandComplete("Close",true);
}*/

//--------------------------------------
ImageCommandSave::ImageCommandSave(ImageViewModel* ptr)
{
    _ImageVM = ptr;
}

void ImageCommandSave::SetParameter(std::shared_ptr<Parameters> param)
{
    this->path = static_pointer_cast<pathParameters>(param)->getPath();
}

void ImageCommandSave::Exec(int id)
{
    _ImageVM->execSaveCommand(path,id);
    _ImageVM->Fire_OnCommandComplete("Save",true);
}

/*void ImageCommandSave::Exec(int id)
{
    _ImageVM->execSaveCommand(path,id);
    _ImageVM->Fire_OnCommandComplete("Save",true);
}
*/
//--------------------------------------
ImageCommandRotate::ImageCommandRotate(ImageViewModel* ptr)
{
    _ImageVM = ptr;
}

void ImageCommandRotate::SetParameter(std::shared_ptr<Parameters> param)
{
    this->angle = static_pointer_cast<intParameters>(param)->getValue();
}


 void ImageCommandRotate::Exec(int id)
{
    _ImageVM->execRotateCommand(angle,id);
    _ImageVM->Fire_OnCommandComplete("Rotate",true);
}

/*
void ImageCommandRotate::Exec(int id)
{
    _ImageVM->execRotateCommand(angle,id);
    _ImageVM->Fire_OnCommandComplete("Rotate",true);
}
*/
//----------------------------------------------
 ImageCommandUndo::ImageCommandUndo(ImageViewModel *ptr)
 {
     _ImageVM = ptr;
 }

 void ImageCommandUndo::SetParameter(std::shared_ptr<Parameters> param)
 {
     image = static_pointer_cast<imageParameters>(param)->image;
 }

 void ImageCommandUndo::Exec(int id)
 {
     _ImageVM->execUndoCommand(image,id);
 }

