#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStack>
#include <QMessageBox>

#include "../Common/notification.h"
#include "../ViewModel/sink/updatesink.h"
#include "mainwindowsink.h"
#include "tabpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class mainwindowsink;
class UpdateSink;
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    QList<TabPage*> ImgTab;     //ImgTab
    int currentID;
    QList<std::shared_ptr<QImage>>* img;

    std::shared_ptr<mainwindowsink> _MainWindowSink;
    std::shared_ptr<UpdateSink> _UpdateSink;

    std::shared_ptr<ICommandBase> _Open;
    std::shared_ptr<ICommandBase> _Close;
    std::shared_ptr<ICommandBase> _Save;
    //std::shared_ptr<ICommandBase> _SaveAs;
    std::shared_ptr<ICommandBase> _Rotate;
    std::shared_ptr<ICommandBase> _Gray;
    std::shared_ptr<ICommandBase> _Blur;
    std::shared_ptr<ICommandBase> _Sharp;
    std::shared_ptr<ICommandBase> _ZoomIn;
    std::shared_ptr<ICommandBase> _ZoomOut;
    std::shared_ptr<ICommandBase> _Undo;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int newTab(QString);  //create a new tab
    int currentTabIndex();  //get current tab obj

    void update();
    void setImages(QList<std::shared_ptr<QImage>>*);

    void EnableOp();
    void DisableOp();

    void Open(const QString &fileName);
    void Close(const int index);
    void Save();
    void Save(const QString &fileName);
    void Gray();
    void Blur();
    void Sharp();
    void Rotate(int angle);
    void ZoomIn();
    void ZoomOut();
    void Undo();

    //bind functions
    void BindingCommandOpen(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandClose(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandSave(const std::shared_ptr<ICommandBase>& ptr);
    //void BindingCommandSaveAs(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandGray(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandBlur(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandSharp(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandRotate(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandZoomIn(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandZoomOut(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandUndo(const std::shared_ptr<ICommandBase>& ptr);

    std::shared_ptr<IPropertyNotification> getUpdateSink(void); //update current img, called
    std::shared_ptr<ICommandNotification> getMainSink(void);   //make sure cmd succeeded

private slots:
    void on_actionOpen_triggered();
    void on_tabWidget_tabCloseRequested(int index);     //tab close
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();

    //void on_actionCut_triggered();
    void on_actionRotate_90_triggered();
    void on_actionRotate_270_triggered();
    void on_actionRotate_180_triggered();
    void on_actionZoom_in_triggered();
    void on_actionZoom_out_triggered();

    void on_actionGray_triggered();
    void on_actionBlur_triggered();
    void on_actionSharp_triggered();

    void on_actionUndo_triggered();

};
#endif // MAINWINDOW_H
