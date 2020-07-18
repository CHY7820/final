#include "tabpage.h"
#include "ui_tabpage.h"
#include <QFileInfo>


TabPage::TabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabPage)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
}

TabPage::~TabPage()
{
    undoStack.clear();
    delete ui;
}

void TabPage::Update()
{
    ui->graphicsView->setScene(new QGraphicsScene);
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*image));
}

void TabPage::setFileDir(QString str)
{
    filename = str;

}
void TabPage::setTitle(QString str)
{
    title = str;
}

void TabPage::setImage(std::shared_ptr<QImage> img)
{
    this->image = img;
}

QString TabPage::getFileName()
{
    QFileInfo fileInfo(filename);
    return fileInfo.fileName();
}
QString TabPage::getFileDir()
{
    return filename;
}

QString TabPage::getTitle()
{
    return title;
}



bool TabPage::StackEmpty()
{
    return undoStack.empty();
}

void TabPage::StackClear()
{
    undoStack.clear();
}

void TabPage::PushStack(QImage img)
{
    undoStack.push(img);
}

QImage TabPage::PopStack()
{
    QImage img = undoStack.pop();
    return img;
}
