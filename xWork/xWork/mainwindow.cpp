#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("xWork");
    this->setMinimumSize(700,600);
    /*最大化显示窗口++*/
    this->setWindowState(Qt::WindowMaximized);

    newfile_action=new QAction(QIcon(":/image/new.ico"),"",this);
    save_action=new QAction(QIcon(":/image/save.ico"),"",this);
    saveas_action=new QAction(QIcon(":/image/saveas.ico"),"",this);
    open_action=new QAction(QIcon(":/image/open.ico"),"",this);
    close_action=new QAction(QIcon(":/image/close.ico"),"",this);
    pen_action=new QAction(QIcon(":/image/pen.ico"),"",this);
    earse_action=new QAction(QIcon(":/image/erase.ico"),"",this);
    forward_action=new QAction(QIcon(":/image/forward.ico"),"",this);    //后退
    copy_action=new QAction(QIcon(":/image/copy.ico"),"",this);
    paste_action=new QAction(QIcon(":/image/paste.ico"),"",this);
    turnup_action=new QAction(QIcon(":/image/up.ico"),"",this);
    turndown_action=new QAction(QIcon(":/image/down.ico"),"",this);
    turndefault_action=new QAction(QIcon(":/image/default.ico"),"",this);

    ui->mainToolBar->addAction(newfile_action);
    ui->mainToolBar->addAction(save_action);
    ui->mainToolBar->addAction(saveas_action);
    ui->mainToolBar->addAction(open_action);
    ui->mainToolBar->addAction(close_action);
    ui->mainToolBar->addAction(pen_action);
    ui->mainToolBar->addAction(earse_action);
    ui->mainToolBar->addAction(forward_action);
    ui->mainToolBar->addAction(copy_action);
    ui->mainToolBar->addAction(paste_action);
    ui->mainToolBar->addAction(turnup_action);
    ui->mainToolBar->addAction(turndown_action);
    ui->mainToolBar->addAction(turndefault_action);

    dock_widget=new QDockWidget;
    dock_widget->setWindowTitle("  画图参数");
    dock_widget->setMinimumWidth(200);
    params_widget=new ParamsWidget;
    dock_widget->setWidget(params_widget);
    this->addDockWidget(Qt::LeftDockWidgetArea,dock_widget);    //放在主窗体的左边

    scroll_area=new QScrollArea;
    paint_widget=new PainterWidget;
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(paint_widget);
    scroll_area->setBackgroundRole(QPalette::Dark);            //设置背景色为黑色

    QVBoxLayout* v=new QVBoxLayout;
    v->addWidget(scroll_area);
    v->setMargin(10);               //设置控件与窗体左右的边距

    setMouseTracking(true);         //开启鼠标实时追踪，监听鼠标移动事件，默认只有按下时才监听
    /*MainWindow 和 Widget有点不一样,MainWindow需要这样,而Widget this->setLayout(v)即可*/
    ui->centralWidget->setLayout(v);

    InitFunc();
    ConnectFunc();
}

void MainWindow::InitFunc()
{
     paint_flag=false;
}

void MainWindow::ConnectFunc()
{
    connect(params_widget,SIGNAL(SetDrawTypeFlagSignal(int)),paint_widget,SLOT(SetDrawTypeFlagSLots(int)));
    connect(params_widget,SIGNAL(SetPenSizeSignal(int)),paint_widget,SLOT(SetPenSizeSlots(int)));
    connect(params_widget,SIGNAL(SetPenColorSignal(QColor)),paint_widget,SLOT(SetPenColorSlots(QColor)));
    connect(params_widget,SIGNAL(SetBgColorSignal(QColor)),paint_widget,SLOT(SetBgColorSlots(QColor)));
    connect(params_widget,SIGNAL(SetPenTypeSignal(int)),paint_widget,SLOT(SetPenTypeSlots(int)));

    connect(this,SIGNAL(SetPaintFlagSignal(int)),paint_widget,SLOT(SetPaintFlagSlots(int)));
    connect(this,SIGNAL(SavePixmapSignal()),paint_widget,SLOT(SavePixmapSlots()));
    connect(this,SIGNAL(SaveAsPixmapSignal()),paint_widget,SLOT(SaveAsPixmapSlots()));
    connect(this,SIGNAL(OpenPixmapSignal()),paint_widget,SLOT(OpenPixmapSlots()));
    connect(this,SIGNAL(NewFileSignal()),paint_widget,SLOT(NewFileSlots()));
    connect(this,SIGNAL(TurnUpSignal()),paint_widget,SLOT(TurnUpSlots()));
    connect(this,SIGNAL(TurnDownSignal()),paint_widget,SLOT(TurnDownSlots()));
    connect(this,SIGNAL(TurnDefaultSignal()),paint_widget,SLOT(TurnDefaultSlots()));
    connect(this,SIGNAL(ForwardSignal()),paint_widget,SLOT(ForwardSlots()));
    connect(this,SIGNAL(CloseSignal()),paint_widget,SLOT(CloseSlots()));

    connect(pen_action,SIGNAL(triggered(bool)),this,SLOT(PenActionSlots()));
    connect(save_action,SIGNAL(triggered(bool)),this,SLOT(SaveActionSlots()));
    connect(saveas_action,SIGNAL(triggered(bool)),this,SLOT(SaveAsActionSlots()));
    connect(close_action,SIGNAL(triggered(bool)),this,SLOT(CloseActionSlots()));
    connect(open_action,SIGNAL(triggered(bool)),this,SLOT(OpenActionSlots()));
    connect(newfile_action,SIGNAL(triggered(bool)),this,SLOT(NewfileActionSlots()));
    connect(forward_action,SIGNAL(triggered(bool)),this,SLOT(ForwardActionSlots()));
    connect(turnup_action,SIGNAL(triggered(bool)),this,SLOT(TurnUpActionSlots()));
    connect(turndown_action,SIGNAL(triggered(bool)),this,SLOT(TurnDownActionSlots()));
    connect(turndefault_action,SIGNAL(triggered(bool)),this,SLOT(TurnDeaultActionSlots()));
}

void MainWindow::NewfileActionSlots()
{
    emit NewFileSignal();
}

void MainWindow::PenActionSlots()
{
    if(!paint_flag)
    {
        paint_flag=true;
    }
    else
    {
        paint_flag=false;
    }
    emit SetPaintFlagSignal(paint_flag);
}

void MainWindow::SaveActionSlots()
{
    emit SavePixmapSignal();
}

void MainWindow::SaveAsActionSlots()
{
    emit SaveAsPixmapSignal();
}

void MainWindow::CloseActionSlots()
{
    emit CloseSignal();
}

void MainWindow::OpenActionSlots()
{
    emit OpenPixmapSignal();
}

void MainWindow::ForwardActionSlots()
{
    emit ForwardSignal();
}

void MainWindow::TurnUpActionSlots()
{
    emit TurnUpSignal();
}

void MainWindow::TurnDownActionSlots()
{
    emit TurnDownSignal();
}

void MainWindow::TurnDeaultActionSlots()
{
    emit TurnDefaultSignal();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int res=QMessageBox::question(this,tr("Exit Program"),
                                  QString(tr("Are You Exit Program?")),
                                  QMessageBox::Yes|QMessageBox::No);
    if(res==QMessageBox::No)
    {
        event->ignore();
    }
    else if(res==QMessageBox::Yes)
    {
//        等待线程退出
//        this->update_thread->CloseThread();
//        update_thread->wait();

        event->accept();
    }
}
