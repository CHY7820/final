#ifndef BASICCOMMAND_H
#define BASICCOMMAND_H
#include "../../Common/notification.h"
#include<QImage>
using namespace std;
class ImageViewModel;

class ImageCommandOpen :public ICommandBase
{
private:
    ImageViewModel* _ImageVM;

    QString path;
public:
    ImageCommandOpen(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param);
    virtual void Exec(int id) ;
    //virtual void Exec(int id) ;
};

class ImageCommandClose :public ICommandBase
{
private:
    ImageViewModel* _ImageVM;

public:
    ImageCommandClose(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param);
    virtual void Exec(int id) override;
    //virtual void Exec(int id) ;
};

class ImageCommandSave:public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
    QString path;
public:
    ImageCommandSave(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param) override;
    virtual void Exec(int id) override;
    //virtual void Exec(int id) ;
};

class ImageCommandRotate:public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
    int angle;
public:
    ImageCommandRotate(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param) override;
    virtual void Exec(int id) override;
    //virtual void Exec(int id) ;
};

class ImageCommandUndo:public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
    QImage image;
public:
    ImageCommandUndo(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param) override;
    virtual void Exec(int id) override;
};

#endif // BASICCOMMAND_H
