#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "../Common/notification.h"
#include <memory>

using namespace cv;

class ImageModel: public Proxy_PropertyNotification<ImageModel>, public Proxy_CommandNotification<ImageModel>
{
public:
    ImageModel();
    ~ImageModel(){}
//    std::shared_ptr<Image> getImage();

    std::shared_ptr<Mat> getImage(int id);
    void setMat(const cv::Mat &mat,int id);

    void SetCurrentId(int id);
    int GetCurrentId() const;

    void Open(const QString& str,int id);
    void Close(int id);
    void Save(const QString& path,int id);

    void Rotate(int,int id);
    void Gray(int id);
    void Blur(int,int,int id);
    void Sharp(int id);
    void ZoomIn(int id);
    void ZoomOut(int id);

private:
    int _Id;
    //std::vector<std::shared_ptr<Mat>> _Images;

    QList<std::shared_ptr<Mat>> _Images;
};
#endif // IMAGEMODEL_H
