#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPoint>

#include <QRect>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtMath>
#include <QVector>

#include <QDebug>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTextEdit>

typedef struct
{
    QPoint start_point;
    QPoint end_point;
    QColor pen_color;
    QColor bg_color;
    Qt::PenStyle pen_style;
    int    pen_size;
}Params;                 //直线,矩形,椭圆,圆参数

typedef struct
{
    QPoint point;
    QColor pen_color;
    QColor bg_color;
    Qt::PenStyle pen_style;
    int    pen_size;
}PointsParams;           //点参数

typedef struct
{
    QVector<QPoint> point_vector;
    QColor pen_color;
    QColor bg_color;
    Qt::PenStyle pen_style;
    int    pen_size;
}LinesParams;            //折线，曲线参数

typedef struct
{
    QString text_str;
    QColor pen_color;
    QColor bg_color;
    Qt::PenStyle pen_style;
    int    pen_size;
}TextParams;             //文字参数

class PainterWidget : public QWidget
{
    Q_OBJECT
public:
    PainterWidget(QWidget *parent = 0);
    void InitFunc();
signals:

public slots:
    void NewFileSlots();
    void SavePixmapSlots();
    void SaveAsPixmapSlots();
    void CloseSlots();
    void OpenPixmapSlots();
    void SetPaintFlagSlots(int );
    void SetDrawTypeFlagSLots(int);

    void SetPenColorSlots(QColor );
    void SetPenSizeSlots(int );
    void SetBgColorSlots(QColor);
    void SetPenTypeSlots(int );

    void AddTexts(); //添加文字

    void TurnUpSlots();            //放大
    void TurnDownSlots();          //缩小
    void TurnDefaultSlots();       //恢复默认大小
    void ForwardSlots();           //撤销槽函数
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void contextMenuEvent(QContextMenuEvent *);
    void keyPressEvent(QKeyEvent *);
private:
    QPixmap pixmap;
    QPen    pen;
    QColor  pen_color;
    QColor  bg_color;
    Qt::PenStyle pen_style;
    int     pen_size;
    QTextEdit *_tEdit;              //文本输入框

    QPoint  start_point;
    QPoint  end_point;

    bool    is_open_flag;
    bool    is_drag_flag;            //拖拽标记
    int     drawtype_flag;           //绘画类型标记
    bool    press_flag;              //鼠标左键按下标记
    bool    paint_flag;              //绘画标记

    QVector<int>  drawtype_vector;               //类型容器，存放总幅图第几个图型的类型

    QVector<PointsParams> points_vector;         //点    1
    QVector<Params>  lines_vector;               //直线 2
    QVector<Params>  rect_vector;                //矩形3
    QVector< LinesParams > curveline_vector;     //曲线4
    QVector<Params>  ellipse_vector;             //椭圆5
    QVector<Params>  circle_vector;              //圆6
    QVector< LinesParams > brokenline_vector;    //折线7
    QVector<TextParams>  _text;                  //文字集合8-1
    QVector<QPoint>   _tpoint;                   //文字位置集合8-2
};

#endif // PAINTERWIDGET_H
