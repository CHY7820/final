#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <QObject>
#include <QImage>

class Parameters
{
public:
    Parameters(){};
};

class pathParameters:public Parameters
{
private:
    QString filepath;
public:
    pathParameters(QString newPath):filepath(newPath){}
    QString getPath()
    {
        return filepath;
    }
};

class intParameters:public Parameters
{
private:
    int value;
public:
    intParameters(int value):value(value){}
    int getValue()
    {
        return value;
    }

};

class blurParameters:public Parameters
{
public:
    blurParameters(int ksize =5,int anchor = 5):ksize(ksize),anchor(anchor){}
    int ksize,anchor;
};

class imageParameters : public Parameters
{
public:
    imageParameters(const QImage &img) : image(img) {}

    QImage image;
};

#endif // PARAMETERS_H
