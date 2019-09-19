#include "paramswidget.h"

ParamsWidget::ParamsWidget(QWidget *parent) : QWidget(parent)
{
    drawtype_label=new QLabel("选择图型:");
    drawtype_combox=new QComboBox;
    drawtype_combox->setMinimumWidth(125);

    drawtype_combox->addItem(QIcon(":/drawtype/point.ico"),"点");       //1
    drawtype_combox->addItem(QIcon(":/drawtype/line.ico"),"直线");       //2
    drawtype_combox->addItem(QIcon(":/drawtype/rectangle.ico"),"矩形");  //3
    drawtype_combox->addItem(QIcon(":/drawtype/ curves.ico"),"曲线");    //4
    drawtype_combox->addItem(QIcon(":/drawtype/ellipse.ico"),"椭圆");    //5
    drawtype_combox->addItem(QIcon(":/drawtype/circular.ico"),"圆");     //6
    drawtype_combox->addItem(QIcon(":/drawtype/brokenline.ico"),"折线"); //7
    drawtype_combox->addItem(QIcon(":/drawtype/text.ico"),"文字");       //8
    drawtype_combox->addItem(QIcon(":/drawtype/circlearc.ico"),"圆弧");    //9

    QHBoxLayout* h1=new QHBoxLayout;
    h1->addWidget(drawtype_label);
    h1->addWidget(drawtype_combox);

    pentype_label=new QLabel("画笔类型");
    pentype_combox=new QComboBox;
    pentype_combox->setMinimumWidth(125);
    //pentype_combox->addItem(QIcon(""),"缺省值");
    pentype_combox->addItem(QIcon(""),"______");         //实线
    pentype_combox->addItem(QIcon(""),"_ _ _ _");        //短划线
    pentype_combox->addItem(QIcon(""),"............");   //虚线
    pentype_combox->addItem(QIcon(""),"_._._._");        //点画点
    pentype_combox->addItem(QIcon(""),"_.._.._..");      //双点画线

    QHBoxLayout* h2=new QHBoxLayout;
    h2->addWidget(pentype_label);
    h2->addWidget(pentype_combox);

    penwidth_label=new QLabel("画笔线宽");
    penwidth_combox=new QComboBox;
    penwidth_combox->setMinimumWidth(125);
    penwidth_combox->addItem(QIcon(""),"1");
    penwidth_combox->addItem(QIcon(""),"2");
    penwidth_combox->addItem(QIcon(""),"3");
    penwidth_combox->addItem(QIcon(""),"4");
    penwidth_combox->addItem(QIcon(""),"5");
    penwidth_combox->addItem(QIcon(""),"6");
    penwidth_combox->addItem(QIcon(""),"7");
    penwidth_combox->addItem(QIcon(""),"8");
    penwidth_combox->addItem(QIcon(""),"9");
    penwidth_combox->addItem(QIcon(""),"10");
    QHBoxLayout* h3=new QHBoxLayout;
    h3->addWidget(penwidth_label);
    h3->addWidget(penwidth_combox);

    pencolor_label=new QLabel("画笔颜色");
    pencolor_combox=new QComboBox;
    pencolor_combox->setMinimumWidth(125);

    QHBoxLayout* h4=new QHBoxLayout;
    h4->addWidget(pencolor_label);
    h4->addWidget(pencolor_combox);

    bgcolor_label=new QLabel("填充颜色");
    gbcolor_combox=new QComboBox;
    gbcolor_combox->setMinimumWidth(125);
    QHBoxLayout* h5=new QHBoxLayout;
    h5->addWidget(bgcolor_label);
    h5->addWidget(gbcolor_combox);

    defaultparam_btn=new QPushButton("默  认  重  置");
    defaultparam_btn->setFixedSize(125,29);
    QHBoxLayout* h6=new QHBoxLayout;
    h6->addStretch();
    h6->addWidget(defaultparam_btn);

    QStringList colorList = QColor::colorNames();
    QString color;
    foreach (color, colorList)
    {
        QPixmap pix(QSize(80/*70*/,20));
        pix.fill(QColor(color));
        pencolor_combox->addItem(QIcon(pix), NULL);
        pencolor_combox->setIconSize(QSize(80/*70*/,20));
        pencolor_combox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gbcolor_combox->addItem(QIcon(pix), NULL);
        gbcolor_combox->setIconSize(QSize(80/*70*/,20));
        gbcolor_combox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
    colorlist_size=colorList.size();
    pencolor_combox->setCurrentIndex(7);                       //default black
    gbcolor_combox->setCurrentIndex(colorlist_size-8);       //default None

    QVBoxLayout* v=new QVBoxLayout;
    v->addLayout(h1);
    v->addLayout(h2);
    v->addLayout(h3);
    v->addLayout(h4);
    v->addLayout(h5);
    v->addLayout(h6);
    v->setMargin(10);
    v->addStretch();
    this->setLayout(v);

    InitFunc();
    ConnectFunc();
}

void ParamsWidget::InitFunc()
{

}

void ParamsWidget::ConnectFunc()
{
    connect(drawtype_combox,SIGNAL(currentIndexChanged(int)),this,SLOT(CurrentIndexSlots(int)));
    connect(pentype_combox,SIGNAL(currentIndexChanged(int)),this,SLOT(CurrentIndexPenTypeSlots(int)));

    connect(pencolor_combox,SIGNAL(currentIndexChanged(int)),this,SLOT(PenColorCurIndexSlots()));
    connect(penwidth_combox,SIGNAL(currentIndexChanged(int)),this,SLOT(PenWidthCurindexSlots(int)));

    connect(gbcolor_combox,SIGNAL(currentIndexChanged(int)),this,SLOT(BackgroundColorSlots()));
    connect(defaultparam_btn,SIGNAL(clicked(bool)),this,SLOT(DefaultParamBtnSLots()));
}

void ParamsWidget::CurrentIndexSlots(int index)
{
    emit SetDrawTypeFlagSignal(index+1);
}

void ParamsWidget::CurrentIndexPenTypeSlots(int index)
{
    emit SetPenTypeSignal(index);
}

void ParamsWidget::PenWidthCurindexSlots(int index)
{
    emit SetPenSizeSignal(index+1);
}

void ParamsWidget::PenColorCurIndexSlots()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[pencolor_combox->currentIndex()]);
    emit SetPenColorSignal(color);
}

void ParamsWidget::BackgroundColorSlots()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[gbcolor_combox->currentIndex()]);
    emit SetBgColorSignal(color);
}

void ParamsWidget::DefaultParamBtnSLots()
{
    drawtype_combox->setCurrentIndex(0);
    pentype_combox->setCurrentIndex(0);
    penwidth_combox->setCurrentIndex(0);
    pencolor_combox->setCurrentIndex(7);                       //default black
    gbcolor_combox->setCurrentIndex(colorlist_size-8);       //default None
}



