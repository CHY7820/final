#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _MainWindowSink = std::make_shared<mainwindowsink>(this);
    _UpdateSink = std::make_shared<UpdateSink>(this);

    QFile file(":/qss/Qss/PushButton.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    file.close();
    ui->btnUndo->setStyleSheet(styleSheet);
    ui->btnRotate90->setStyleSheet(styleSheet);
    ui->btnRotate180->setStyleSheet(styleSheet);
    ui->btnRotate270->setStyleSheet(styleSheet);
    connect(ui->btnUndo,SIGNAL(clicked()),this,SLOT(on_actionUndo_triggered()));
    connect(ui->btnRotate90,SIGNAL(clicked()),this,SLOT(on_actionRotate_90_triggered()));
    connect(ui->btnRotate270,SIGNAL(clicked()),this,SLOT(on_actionRotate_270_triggered()));
    connect(ui->btnRotate180,SIGNAL(clicked()),this,SLOT(on_actionRotate_180_triggered()));

    DisableOp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    if(ImgTab.empty())
        return;
    ImgTab.at(currentTabIndex())->setImage(img->at(currentTabIndex()));
    ImgTab.at(currentTabIndex())->Update();
}

void MainWindow::setImages(QList<shared_ptr<QImage>>* img)
{
    this->img = img;
}

int MainWindow::newTab(QString file)   //called by open
{
    TabPage* pTab = new TabPage;
    ImgTab.push_back(pTab);

    pTab->setFileDir(file);
    pTab->setTitle(pTab->getFileName());

    int tabindex = ui->tabWidget->addTab(pTab, pTab->getTitle());
    ui->tabWidget->setCurrentIndex(tabindex);

    return tabindex;
}


int MainWindow::currentTabIndex()
{
    return ui->tabWidget->currentIndex();
}

void MainWindow::EnableOp()
{
    ui->menuBasic->setEnabled(true);
    ui->menuFilter->setEnabled(true);
    ui->actionClose->setEnabled(true);
    ui->actionSave->setEnabled(true);
    ui->actionSave_As->setEnabled(true);
    ui->btnUndo->setEnabled(true);
    ui->btnRotate90->setEnabled(true);
    ui->btnRotate180->setEnabled(true);
    ui->btnRotate270->setEnabled(true);
}
void MainWindow::DisableOp()
{
    ui->menuBasic->setEnabled(false);
    ui->menuFilter->setEnabled(false);
    ui->actionClose->setEnabled(false);
    ui->actionSave->setEnabled(false);
    ui->actionSave_As->setEnabled(false);
    ui->btnUndo->setEnabled(false);
    ui->btnRotate90->setEnabled(false);
    ui->btnRotate180->setEnabled(false);
    ui->btnRotate270->setEnabled(false);
}

std::shared_ptr<ICommandNotification> MainWindow::getMainSink(void){
    return std::static_pointer_cast<ICommandNotification>(_MainWindowSink);
}

std::shared_ptr<IPropertyNotification> MainWindow::getUpdateSink(void){
    return std::static_pointer_cast<IPropertyNotification>(_UpdateSink);
}

void MainWindow::on_actionOpen_triggered()
{

    QString filename = QFileDialog::getOpenFileName(this,tr("open Image"),".",tr("Image File(*.png *.jpg *JPG *jpeg *.bmp)"));
    if(filename.isEmpty())
        return;

    newTab(filename);
    this->Open(filename);
    EnableOp();

}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    this->Close(index);

    if(ImgTab.isEmpty())
        DisableOp();
}

void MainWindow::on_actionSave_triggered()
{
    if (QMessageBox::question(this, tr("Question"), tr("Save File?")))
        this->Save();

}

void MainWindow::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save As"),".",tr("Image File(*.png *.jpg *JPG *jpeg *.bmp)"));
    if(filename.isEmpty())
        return;

    ImgTab[currentTabIndex()]->setFileDir(filename);
    ImgTab[currentTabIndex()]->setTitle(ImgTab[currentTabIndex()]->getFileName());
    ui->tabWidget->setTabText(currentTabIndex(),ImgTab[currentTabIndex()]->getTitle());
    this->Save(filename);  
}

void MainWindow::on_actionGray_triggered()
{
    this->Gray();
}

void MainWindow::on_actionBlur_triggered()
{
    this->Blur();
}

void MainWindow::on_actionSharp_triggered()
{
    this->Sharp();
}

void MainWindow::on_actionRotate_90_triggered()
{
    this->Rotate(90);
}

void MainWindow::on_actionRotate_270_triggered()
{
    this->Rotate(-90);
}

void MainWindow::on_actionRotate_180_triggered()
{
    this->Rotate(180);
}

void MainWindow::on_actionZoom_in_triggered()
{
    this->ZoomIn();
}

void MainWindow::on_actionZoom_out_triggered()
{
    this->ZoomOut();
}

void MainWindow::on_actionUndo_triggered()
{
    this->Undo();
}

void MainWindow::BindingCommandOpen(const std::shared_ptr<ICommandBase>& ptr){
    _Open = ptr;
}

void MainWindow::BindingCommandClose(const std::shared_ptr<ICommandBase> &ptr)
{

    _Close = ptr;
}

void MainWindow::BindingCommandSave(const std::shared_ptr<ICommandBase> &ptr)
{
    _Save = ptr;
}

void MainWindow::BindingCommandGray(const std::shared_ptr<ICommandBase>& ptr)
{
    _Gray=ptr;
}
void MainWindow::BindingCommandBlur(const std::shared_ptr<ICommandBase> &ptr)
{
    _Blur=ptr;
}

void MainWindow::BindingCommandSharp(const std::shared_ptr<ICommandBase> &ptr)
{
    _Sharp=ptr;
}

void MainWindow::BindingCommandRotate(const std::shared_ptr<ICommandBase> &ptr)
{
    _Rotate = ptr;
}

void MainWindow::BindingCommandZoomIn(const std::shared_ptr<ICommandBase> &ptr)
{
    _ZoomIn = ptr;
}

void MainWindow::BindingCommandZoomOut(const std::shared_ptr<ICommandBase> &ptr)
{
    _ZoomOut = ptr;
}

void MainWindow::BindingCommandUndo(const std::shared_ptr<ICommandBase> &ptr)
{
    _Undo = ptr;
}

void MainWindow::Open(const QString &fileName)
{
    std::shared_ptr<pathParameters> Param = std::make_shared<pathParameters>(fileName);
    _Open->SetParameter(std::static_pointer_cast<Parameters>(Param));
    qDebug()<<currentTabIndex();
    _Open->Exec(currentTabIndex());  //add id
}

void MainWindow::Close(int index)
{
    TabPage *closingTab=ImgTab[index];

    _Close->Exec(currentTabIndex());
    qDebug()<<"before remove"<<currentTabIndex()<<endl;
    //remove tab
    ui->tabWidget->removeTab(index);
    ImgTab.removeAt(index);
    qDebug()<<"after remove"<<currentTabIndex()<<endl;
    delete closingTab;
}

void MainWindow::Save()
{
    Save(ImgTab[currentTabIndex()]->getFileDir());
}

void MainWindow::Save(const QString &fileName)
{
    int id = currentTabIndex();
    std::shared_ptr<pathParameters> Param = std::make_shared<pathParameters>(fileName);
    _Save->SetParameter(std::static_pointer_cast<Parameters>(Param));
    _Save->Exec(id);

    if(!ImgTab[id]->StackEmpty())
    {
        ImgTab[id]->StackClear();
    }
}

void MainWindow::Gray()
{
    int id = currentTabIndex();
    QImage image = *(img->at(id));
    ImgTab[id]->PushStack(image);
    _Gray->Exec(id);
}

void MainWindow::Blur()
{
    int id = currentTabIndex();
    QImage image = *(img->at(id));
    ImgTab[id]->PushStack(image);
    std::shared_ptr<blurParameters> Param = std::make_shared<blurParameters>();
    _Blur->SetParameter(std::static_pointer_cast<Parameters>(Param));
    _Blur->Exec(id);
}

void MainWindow::Sharp()
{
    int id = currentTabIndex();
    QImage image = *(img->at(id));
    ImgTab[id]->PushStack(image);
    _Sharp->Exec(currentTabIndex());
}

void MainWindow::Rotate(int angle)
{
    int id = currentTabIndex();
    QImage image = *(img->at(id));
    ImgTab[id]->PushStack(image);
    std::shared_ptr<intParameters> Param = std::make_shared<intParameters>(angle);
    _Rotate->SetParameter(std::static_pointer_cast<Parameters>(Param));
    _Rotate->Exec(id);

}

void MainWindow::ZoomIn()
{
    int id = currentTabIndex();
    QImage image = *(img->at(id));
    ImgTab[id]->PushStack(image);
    _ZoomIn->Exec(id);
}

void MainWindow::ZoomOut()
{
    int id = currentTabIndex();
    QImage image = *(img->at(id));
    ImgTab[id]->PushStack(image);
    _ZoomOut->Exec(id);
}

void MainWindow::Undo()
{
   int id = currentTabIndex();
   if(ImgTab[id]->StackEmpty())
       return;

   QImage img = ImgTab[id]->PopStack();
   std::shared_ptr<imageParameters> Param = std::make_shared<imageParameters>(img);
   _Undo->SetParameter(std::static_pointer_cast<Parameters>(Param));
   _Undo->Exec(id);
}
