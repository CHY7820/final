#include "utils.h"

using namespace cv;

QImage Mat2QImage(const cv::Mat &src)
{
    Mat dst;
    cvtColor(src, dst, COLOR_BGR2RGB);
    QImage result((const uchar *)dst.data, dst.cols, dst.rows, dst.step, QImage::Format_RGB888);
    result.bits();   // enforce deep copy
    return result;
}

Mat QImage2Mat(const QImage &src)
{
    Mat result(src.height(), src.width(), CV_8UC3, (uchar *)src.bits(), src.bytesPerLine());
    cvtColor(result, result, COLOR_RGB2BGR);
    return result;
}
