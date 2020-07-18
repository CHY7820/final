#include "../../ViewModel/command/FilterCommands.h"
#include "ViewModel/imageviewmodel.h"

ImageCommandGray::ImageCommandGray(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}

void ImageCommandGray::SetParameter(std::shared_ptr<Parameters> param)
{

}

 void ImageCommandGray::Exec(int id)
{
    _ImageVM->execGrayCommand(id);
    _ImageVM->Fire_OnCommandComplete("GrayCommand", true);
}

/*
void ImageCommandGray::Exec(int id)
{
    _ImageVM->execGrayCommand(id);
    _ImageVM->Fire_OnCommandComplete("GrayCommand", true);
}
*/

void ImageCommandBlur::SetParameter(std::shared_ptr<Parameters> param)
{
    ksize = static_pointer_cast<blurParameters>(param)->ksize;
    anchor = static_pointer_cast<blurParameters>(param)->anchor;
}

ImageCommandBlur::ImageCommandBlur(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}


void ImageCommandBlur::Exec(int id)
{
    _ImageVM->execBlurCommand(ksize, anchor,id);
    _ImageVM->Fire_OnCommandComplete("BlurCommand", true);
}

/*
void ImageCommandBlur::Exec(int id)
{
    _ImageVM->execBlurCommand(ksize, anchor,id);
    _ImageVM->Fire_OnCommandComplete("BlurCommand", true);
}
*/

ImageCommandSharp::ImageCommandSharp(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}
void ImageCommandSharp::SetParameter(std::shared_ptr<Parameters> param){

}


 void ImageCommandSharp::Exec(int id)
{
    _ImageVM->execSharpCommand(id);
    _ImageVM->Fire_OnCommandComplete("SharpCommand", true);
}

/*
void ImageCommandSharp::Exec(int id)
{
    _ImageVM->execSharpCommand(id);
    _ImageVM->Fire_OnCommandComplete("SharpCommand", true);
}
*/

ImageCommandZoomIn::ImageCommandZoomIn(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}
void ImageCommandZoomIn::SetParameter(std::shared_ptr<Parameters> param){

}


 void ImageCommandZoomIn::Exec(int id)
{
    _ImageVM->execZoomInCommand(id);
    _ImageVM->Fire_OnCommandComplete("ZoomIn",true);
}


/*
 * void ImageCommandZoomIn::Exec(int id)
{
    _ImageVM->execZoomInCommand(id);
    _ImageVM->Fire_OnCommandComplete("ZoomIn",true);
}
*/

ImageCommandZoomOut::ImageCommandZoomOut(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}
void ImageCommandZoomOut::SetParameter(std::shared_ptr<Parameters> param){

}

void ImageCommandZoomOut::Exec(int id)
{
    _ImageVM->execZoomOutCommand(id);
    _ImageVM->Fire_OnCommandComplete("ZoomOut",true);
}
/*
void ImageCommandZoomOut::Exec(int id)
{
    _ImageVM->execZoomOutCommand(id);
    _ImageVM->Fire_OnCommandComplete("ZoomOut",true);
}
*/
