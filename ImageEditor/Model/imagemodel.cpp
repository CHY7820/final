#include "imagemodel.h"
#include <QDebug>
ImageModel::ImageModel()
{
    //_Image = std::make_shared<Image>();
    _Images.push_back(std::make_shared<Mat>());
    _Id = 0;
}

std::shared_ptr<Mat> ImageModel::getImage(int id)
{

    return _Images.at(id);
}

void ImageModel::Open(const QString& str,int id)
{
    SetCurrentId(id);
    _Images.push_back(std::make_shared<Mat>());
    *(_Images.at(id)) = cv::imread(str.toLocal8Bit().data(), IMREAD_COLOR);

    Fire_OnPropertyChanged("ImageModel");
}

void ImageModel::Close(int id)
{
    SetCurrentId(id);
    //std::shared_ptr<Mat> delMat = _Images[id];
    _Images.removeAt(id);
}

void ImageModel::Save(const QString & path,int id)
{
    SetCurrentId(id);
    imwrite(path.toLocal8Bit().data(), *_Images[id]);
}
void ImageModel::Rotate(int angle,int id)
{
    SetCurrentId(id);
    auto image = _Images[id];
    switch(angle)
    {
    case 90:
        rotate(*image,*image,ROTATE_90_CLOCKWISE);
        break;
    case -90:
        rotate(*image,*image,ROTATE_90_COUNTERCLOCKWISE);
        break;
    case 180:
        rotate(*image,*image,ROTATE_180);
        break;
    default: break;
    }

    Fire_OnPropertyChanged("ImageModel");
}

void ImageModel::Gray(int id){
    SetCurrentId(id);
        auto image = _Images.at(id);
        cvtColor(*image,*image,COLOR_BGR2GRAY);
        cvtColor(*image,*image,COLOR_GRAY2BGR);
        //qDebug()<<"after gray:"<<image->currentImage.channels();
        Fire_OnPropertyChanged("ImageModel");

}

void ImageModel::Blur(int ksize,int anchor,int id){
    SetCurrentId(id);
    auto image = _Images.at(id);
        blur(*image, *image, Size(ksize,anchor));
        //qDebug()<<"after blur:"<<image->currentImage.channels();
        Fire_OnPropertyChanged("ImageModel");
}

void ImageModel::Sharp(int id){
    SetCurrentId(id);
    auto image = _Images.at(id);
        Mat sharpkernel = (Mat_<float>(3, 3) <<
                    0, -1, 0,
                    -1,10, -1,
                    0, -1, 0);
        filter2D(*image,*image, CV_8UC1, sharpkernel);

        //qDebug()<<"after sharp:"<<image->currentImage.channels();
        Fire_OnPropertyChanged("ImageModel");

}

void ImageModel::ZoomIn(int id)
{
    SetCurrentId(id);
    auto image = _Images.at(id);
        resize(*image, *image, Size(), 1.2, 1.2);
        Fire_OnPropertyChanged("ImageModel");
}

void ImageModel::ZoomOut(int id)
{
    SetCurrentId(id);
    auto image = _Images.at(id);
    resize(*image,*image, Size(), 0.7, 0.7);
    Fire_OnPropertyChanged("ImageModel");

}

void ImageModel::setMat(const cv::Mat &mat,int id)
{
    SetCurrentId(id);
    *_Images.at(id) = mat;
    Fire_OnPropertyChanged("ImageModel");
}

void ImageModel::SetCurrentId(int id)
{
    _Id  = id;
}

int ImageModel::GetCurrentId() const
{
    return _Id;
}







