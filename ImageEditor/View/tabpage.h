#ifndef TABPAGE_H
#define TABPAGE_H

#include <QWidget>
#include <QStack>
#include <memory>
namespace Ui {
class TabPage;
}

class TabPage : public QWidget
{
    Q_OBJECT

public:
    explicit TabPage(QWidget *parent = nullptr);
    ~TabPage();

    void setFileDir(QString str);
    void setTitle(QString str);
    void setImage(std::shared_ptr<QImage>);
    QString getFileName();
    QString getFileDir();
    QString getTitle();

    void Update();

    bool StackEmpty();
    void PushStack(QImage);
    QImage PopStack();
    void StackClear();
private:
    Ui::TabPage *ui;
    QString filename;
    QString title;
    std::shared_ptr<QImage> image;
    QStack<QImage> undoStack;
};

#endif // TABPAGE_H
