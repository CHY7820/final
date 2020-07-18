#ifndef UTILS_H
#define UTILS_H
#include <opencv2/opencv.hpp>
#include <QImage>

QImage Mat2QImage(const cv::Mat &src);
cv::Mat QImage2Mat(const QImage &src);

#endif // UTILS_H
