#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include <QIcon>
#include <QAction>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QComboBox>

#include <QScrollArea>
#include <QCloseEvent>
#include "painterwidget.h"
#include "paramswidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void InitFunc();
    void ConnectFunc();
signals:
    void SavePixmapSignal();
    void SaveAsPixmapSignal();
    void OpenPixmapSignal();
    void SetPaintFlagSignal(int );
    void NewFileSignal();

    void TurnUpSignal();            //放大信号
    void TurnDownSignal();          //缩小信号
    void TurnDefaultSignal();       //恢复默认大小
    void ForwardSignal();           //撤销信号
    void CloseSignal();
public slots:
    void NewfileActionSlots();
    void PenActionSlots();
    void SaveActionSlots();
    void SaveAsActionSlots();
    void CloseActionSlots();
    void OpenActionSlots();
    void ForwardActionSlots();      //撤销槽函数

    void TurnUpActionSlots();       //放大槽函数
    void TurnDownActionSlots();     //缩小槽函数
    void TurnDeaultActionSlots();
protected:
    void changeEvent(QEvent *);
    void closeEvent(QCloseEvent *);
private:
    Ui::MainWindow *ui;
    QAction* newfile_action;
    QAction* open_action;
    QAction* save_action;
    QAction* saveas_action;
    QAction* close_action;
    QAction* pen_action;
    QAction* earse_action;
    QAction* forward_action;          //撤销
    QAction* copy_action;
    QAction* paste_action;
    QAction* turnup_action;           //放大
    QAction* turndown_action;         //缩小
    QAction* turndefault_action;

    QDockWidget* dock_widget;         //可以悬浮的窗口
    ParamsWidget* params_widget;      //

    QScrollArea* scroll_area;
    PainterWidget* paint_widget;      //绘画窗口控件

    bool paint_flag;                  //绘画标记
};

#endif // MAINWINDOW_H
