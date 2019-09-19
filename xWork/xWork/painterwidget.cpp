#include "painterwidget.h"

PainterWidget::PainterWidget(QWidget *parent) : QWidget(parent)
{
    is_open_flag=false;
    is_drag_flag=false;
    press_flag=false;
    paint_flag=false;
    drawtype_flag=1/*9圆弧,8文字,7折线,6,5,4,3,2,1*/;

    setMouseTracking(true);     //开启鼠标实时追踪，监听鼠标移动事件，默认只有按下时才监听

    pen_color=QColor("black");
    bg_color.setRgb(0,0,0,0);   //默认透明填充
    pen_size =1;

    _tEdit=new QTextEdit(this); //初始化文本输入框
    _tEdit->hide();             //隐藏
    InitFunc();
    connect(_tEdit, SIGNAL(textChanged()), this, SLOT(AddTexts()));
}

void PainterWidget::InitFunc()
{
    pen_style=Qt::SolidLine;
}

void PainterWidget::NewFileSlots()
{
    press_flag=false;

    drawtype_vector.clear();             //类型容器，存放总幅图第几个图型的类型
    points_vector.clear();
    lines_vector.clear();
    rect_vector.clear();
    curveline_vector.clear(); //曲线
    ellipse_vector.clear();
    circle_vector.clear();
    brokenline_vector.clear();//折线
    _text.clear();                  //文字集合8
    _tpoint.clear();                   //文字位置集合8
    update();
}

void PainterWidget::SavePixmapSlots()
{
    press_flag=false;
    //弹出文件保存对话框
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存"), "new.jpg", "Image (*.jpg *.png *.bmp)");

    if (fileName.length() > 0)
    {
        _tEdit->hide();//防止文本输入框显示时，将文本框保存到图片
        QPixmap pixmap(size());//新建窗体大小的pixmap
        QPainter painter(&pixmap);//将pixmap作为画布
        painter.fillRect(QRect(0, 0, size().width(), size().height()), Qt::white);//设置绘画区域、画布颜色
        this->render(&painter);//将窗体渲染到painter，再由painter画到画布
        pixmap.copy(QRect(0,0,size().width(),size().height())).save(fileName);//不包含工具栏
    }
}

void PainterWidget::SaveAsPixmapSlots()
{
    press_flag=false;
}

void PainterWidget::CloseSlots()
{
    press_flag=false;
    paint_flag=false;
    drawtype_vector.clear();             //类型容器，存放总幅图第几个图型的类型
    points_vector.clear();
    lines_vector.clear();
    rect_vector.clear();
    curveline_vector.clear(); //曲线
    ellipse_vector.clear();
    circle_vector.clear();
    brokenline_vector.clear();//折线
    _text.clear();                  //文字集合8
    _tpoint.clear();                   //文字位置集合8
    update();
}

void PainterWidget::OpenPixmapSlots()
{
    press_flag=false;
    //弹出文件打开对话框
    QString picPath = QFileDialog::getOpenFileName(this,tr("打开"),"","Image Files(*.jpg *.png)");
    if(!picPath.isEmpty())//用户选择了文件
    {
        QPixmap pix;
        pix.load(picPath);//加载图片
        QPainter p(&pixmap);
        p.drawPixmap(0,0,pix);//添加工具栏的空间
        is_open_flag = 1;//设置文件打开标志
        update();//触发窗体重绘，将图片画到窗体
    }
}

void PainterWidget::SetPaintFlagSlots(int _paint_flag)
{
    paint_flag=_paint_flag;
    press_flag=false;
    _tEdit->hide();
}

void PainterWidget::SetDrawTypeFlagSLots(int _drawtype)
{
    this->drawtype_flag=_drawtype;
    press_flag=false;
    _tEdit->hide();
}

void PainterWidget::SetPenColorSlots(QColor _color)
{
    pen_color=_color;
    press_flag=false;
    update();
}

void PainterWidget::SetPenSizeSlots(int _size)
{
    pen_size = _size;
    press_flag=false;
    update();
}

void PainterWidget::SetBgColorSlots(QColor _color)
{
    bg_color=_color;
    press_flag=false;
    update();
}

void PainterWidget::SetPenTypeSlots(int index)
{
    switch(index)
    {
    case 0:
        pen_style=Qt::SolidLine;
        break;
    case 1:
        pen_style=Qt::DashLine;
        break;
    case 2:
        pen_style=Qt::DotLine;
        break;
    case 3:
        pen_style=Qt::DashDotLine;
        break;
    case 4:
        pen_style=Qt::DashDotDotLine;
        break;
    }
    update();
}

void PainterWidget::AddTexts()
{
    QString& last = _text.last().text_str;//拿到最后一个文本
    _tEdit->setTextColor(_text.last().pen_color);
//    _tEdit->setFontPointSize(_text.last().pen_size);
    last = _tEdit->toPlainText();//将输入框文本作为文本
}

void PainterWidget::TurnUpSlots()              //放大
{
//    qDebug()<<"TurnUpSlots()";

}

void PainterWidget::TurnDownSlots()            //缩小
{
//    qDebug()<<"TurnDownSlots()";

}

void PainterWidget::TurnDefaultSlots()
{
//    qDebug()<<"TurnDefaultSlots()";

}

void PainterWidget::ForwardSlots()             //撤销
{
//    qDebug()<<"ForwardSlots()";
    if(drawtype_vector.size()>0){
        press_flag=false;
        int last_type=drawtype_vector.last();
        drawtype_vector.pop_back();
        switch(last_type)
        {
        case 1:
        {
            if(points_vector.size()>0){
                points_vector.pop_back();
            }
        }
            break;
        case 2:
        {
            if(lines_vector.size()>0)
            {
                lines_vector.pop_back();
            }
        }
            break;
        case 3:
        {
            if(rect_vector.size()>0)
            {
                rect_vector.pop_back();
            }
        }
            break;
        case 4:
        {
            if(curveline_vector.size()>0)
            {
                curveline_vector.pop_back();
            }
        }
            break;
        case 5:
        {
            if(ellipse_vector.size()>0)
            {
                ellipse_vector.pop_back();
            }
        }
            break;
        case 6:
        {
            if(circle_vector.size()>0)
            {
                circle_vector.pop_back();
            }
        }
            break;
        case 7:
        {
            if(brokenline_vector.size()>0)
            {
                brokenline_vector.pop_back();
            }
        }
            break;
        case 8:
        {
            if(_text.size()>0)
            {
                _text.pop_back();
                _tpoint.pop_back();
            }
        }
            break;
        case 9:
            break;
        }
        update();
    }
}

void PainterWidget::mousePressEvent(QMouseEvent *e)
{
    if(!paint_flag) return ;
    if(e->button()==Qt::LeftButton){
        start_point=e->pos();
        if(drawtype_flag==1)                  //点
        {
            drawtype_vector.push_back(1);
            PointsParams point;
            point.point=e->pos();
            point.pen_color=pen_color;
            point.pen_size=pen_size;
            point.bg_color=bg_color;
            point.pen_style=pen_style;
            points_vector.append(point);
            update();
        }
        else if(drawtype_flag==2)              //直线
        {
            Params lineparam;
            lineparam.start_point=start_point;
            lineparam.end_point=start_point;
            lineparam.pen_color=pen_color;
            lineparam.bg_color=bg_color;
            lineparam.pen_style=pen_style;
            lineparam.pen_size=pen_size;
            lines_vector.append(lineparam);
            drawtype_vector.push_back(2);
            press_flag=true;
            update();
        }
        else if(drawtype_flag==3)             //矩形
        {
            Params rectparam;
            rectparam.start_point=start_point;
            rectparam.end_point=start_point;
            rectparam.pen_color=pen_color;
            rectparam.bg_color=bg_color;
            rectparam.pen_style=pen_style;
            rectparam.pen_size=pen_size;
            rect_vector.append(rectparam);
            drawtype_vector.push_back(3);
            press_flag=true;
            update();
        }
        else if(drawtype_flag==4)               //曲线
        {
            LinesParams linesparam;
            linesparam.point_vector.append(start_point);
            linesparam.pen_color=pen_color;
            linesparam.bg_color=bg_color;
            linesparam.pen_style=pen_style;
            linesparam.pen_size=pen_size;

            curveline_vector.append(linesparam);
            drawtype_vector.push_back(4);
            press_flag=true;
            update();
        }
        else if(drawtype_flag==5)              //椭圆
        {
            Params ellipseparam;
            ellipseparam.start_point=start_point;
            ellipseparam.end_point=start_point;
            ellipseparam.pen_color=pen_color;
            ellipseparam.bg_color=bg_color;
            ellipseparam.pen_style=pen_style;
            ellipseparam.pen_size=pen_size;
            ellipse_vector.append(ellipseparam);
            drawtype_vector.push_back(5);
            press_flag=true;
            update();
        }
        else if(drawtype_flag==6)              //圆
        {
            Params circleparam;
            circleparam.start_point=start_point;
            circleparam.end_point=start_point;
            circleparam.pen_color=pen_color;
            circleparam.bg_color=bg_color;
            circleparam.pen_style=pen_style;
            circleparam.pen_size=pen_size;
            circle_vector.append(circleparam);
            drawtype_vector.push_back(6);
            press_flag=true;
            update();
        }
        else if(drawtype_flag==7)         //折线
        {
            if(!press_flag){
                LinesParams linesparam;
                linesparam.point_vector.append(start_point);
                linesparam.point_vector.append(start_point);
                linesparam.pen_color=pen_color;
                linesparam.bg_color=bg_color;
                linesparam.pen_style=pen_style;
                linesparam.pen_size=pen_size;

                brokenline_vector.append(linesparam);
                drawtype_vector.push_back(7);
                press_flag=true;
                update();
            }
        }
        else if(drawtype_flag==8)       //文字
        {
            update();//触发窗体重绘
            QPoint p;//鼠标按下，文字开始
            _tpoint.append(p);//将文字坐标添加到文字位置集合
            QPoint& lastp = _tpoint.last();//拿到新文字
            lastp = e->pos();//记录鼠标的坐标
            _tEdit->setGeometry(lastp.x()-6,lastp.y()-17,120,90);//设置文本框的位置、大小
            _tEdit->show();//显示文本输入框

            TextParams textparam;
            textparam.pen_color=pen_color;
            textparam.bg_color=bg_color;
            textparam.pen_style=pen_style;
            textparam.pen_size=pen_size;
            textparam.text_str="";
            _text.append(textparam);//添加文本到文本集合
            _tEdit->clear();//因为全局只有一个，所以使用之前要清空
            drawtype_vector.push_back(8);
        }
    }
    else if(e->button()==Qt::RightButton)                   //处理鼠标右键按下
    {
        if(drawtype_flag==7){          //折线取消
            QVector<QPoint> & points=brokenline_vector.last().point_vector;
            points.pop_back();
            press_flag=false;
            update();
        }
        if(drawtype_flag==8)
        {
            press_flag=false;
            _tEdit->hide();
            update();
        }
    }
}

void PainterWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(!paint_flag) return ;
    if(press_flag==true){
        if(drawtype_flag==2){
            Params & lineparam=lines_vector.last();
            lineparam.end_point=e->pos();
            update();
        }
        else if(drawtype_flag==3){
            Params & rectparam=rect_vector.last();
            rectparam.end_point=e->pos();
            update();
        }
        else if(drawtype_flag==4)
        {
            QVector<QPoint> & points=curveline_vector.last().point_vector;
            points.append(e->pos());
            update();
        }
        else if(drawtype_flag==5){
            Params & ellipseparam=ellipse_vector.last();
            ellipseparam.end_point=e->pos();
            update();
        }
        else if(drawtype_flag==6)
        {
            Params & circleparam=circle_vector.last();
            circleparam.end_point=e->pos();
            update();
        }
        else if(drawtype_flag==7)
        {
            QVector<QPoint> & points=brokenline_vector.last().point_vector;
            QPoint& pp=points.last();
            pp.setX(e->x());
            pp.setY(e->y());
            update();
        }
    }
}

void PainterWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(!paint_flag) return ;
    if(e->button()==Qt::LeftButton)
    {
        end_point=e->pos();
        if(drawtype_flag==2){
            Params & lineparam=lines_vector.last();
            lineparam.end_point=e->pos();
            press_flag=false;
            update();
        }
        else if(drawtype_flag==3){
            Params & rectparam=rect_vector.last();
            rectparam.end_point=e->pos();
            press_flag=false;
            update();
        }
        else if(drawtype_flag==4)
        {
            QVector<QPoint> & points=curveline_vector.last().point_vector;
            points.append(e->pos());
            press_flag=false;
            update();
        }
        else if(drawtype_flag==5){
            Params & ellipseparam=ellipse_vector.last();
            ellipseparam.end_point=e->pos();
            press_flag=false;
            update();
        }
        else if(drawtype_flag==6)
        {
            Params & circleparam=circle_vector.last();
            circleparam.end_point=e->pos();
            press_flag=false;
            update();
        }
        else if(drawtype_flag==7)
        {
            QVector<QPoint> & points=brokenline_vector.last().point_vector;
            QPoint& pp=points.last();
            pp.setX(e->x());
            pp.setY(e->y());
            points.append(e->pos());
            update();
        }
    }
}

void PainterWidget::contextMenuEvent(QContextMenuEvent *e)
{

}

void PainterWidget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
      case Qt::Key_Escape:
        this->close();
        break;
     default:
        QWidget::keyPressEvent(e);
    }
}

void PainterWidget::paintEvent(QPaintEvent *e)
{
    if(!is_open_flag){
        pixmap=QPixmap(size());
        pixmap.fill(Qt::white);
    }
    QPixmap pix=pixmap;
    QPainter p(&pix);   //将_pixmap作为画布

    unsigned int point_index=0,line_index=0,rect_index=0,curve_index=0,ellipse_index=0,\
            circle_index=0,broken_index=0,text_index=0;
    for(int typeindex=0;typeindex<drawtype_vector.size();++typeindex)
    {
        if(drawtype_vector.at(typeindex)==1){     //draw point
            p.setRenderHint( QPainter::Antialiasing, true );    //抗锯齿
            pen.setColor(points_vector.at(point_index).pen_color);
            pen.setWidth(points_vector.at(point_index).pen_size);
            pen.setStyle(points_vector.at(point_index).pen_style);
            p.setPen(pen);
            p.drawPoint(points_vector.at(point_index).point);
            ++point_index;
        }
        else if(drawtype_vector.at(typeindex)==2){ //draw line
            p.setRenderHint( QPainter::Antialiasing, true );    //抗锯齿
            pen.setColor(lines_vector.at(line_index).pen_color);
            pen.setStyle(lines_vector.at(line_index).pen_style);
            pen.setWidth(lines_vector.at(line_index).pen_size);
            p.setPen(pen);
            p.drawLine(lines_vector.at(line_index).start_point,lines_vector.at(line_index).end_point);
            ++line_index;
        }
        else if(drawtype_vector.at(typeindex)==3){  //draw rectangle
            p.setRenderHint( QPainter::Antialiasing, true );    //抗锯齿
            pen.setColor(rect_vector.at(rect_index).pen_color);
            pen.setStyle(rect_vector.at(rect_index).pen_style);
            pen.setWidth(rect_vector.at(rect_index).pen_size);
            p.setBrush(rect_vector.at(rect_index).bg_color); //++设置填充色
            p.setPen(pen);
            p.drawRect(QRect(rect_vector.at(rect_index).start_point,rect_vector.at(rect_index).end_point));
            ++rect_index;
        }
        else if(drawtype_vector.at(typeindex)==4){
            p.setRenderHint( QPainter::Antialiasing, true );    //抗锯齿
            pen.setStyle(curveline_vector.at(curve_index).pen_style);
            pen.setColor(curveline_vector.at(curve_index).pen_color);
            pen.setWidth(curveline_vector.at(curve_index).pen_size);
            p.setPen(pen);
            const QVector<QPoint> & points=curveline_vector.at(curve_index).point_vector;
            for(int i=0;i<points.size()-1;++i)
            {
                p.drawLine(points.at(i),points.at(i+1));
            }
            ++curve_index;
        }
        else if(drawtype_vector.at(typeindex)==5)
        {
            p.setRenderHint( QPainter::Antialiasing, true );    //抗锯齿
            pen.setColor(ellipse_vector.at(ellipse_index).pen_color);
            pen.setStyle(ellipse_vector.at(ellipse_index).pen_style);
            pen.setWidth(ellipse_vector.at(ellipse_index).pen_size);
            p.setBrush(ellipse_vector.at(ellipse_index).bg_color); //++设置填充色
            p.setPen(pen);
            p.drawEllipse(QRect(ellipse_vector.at(ellipse_index).start_point,ellipse_vector.at(ellipse_index).end_point));
            ++ellipse_index;
        }
        else if(drawtype_vector.at(typeindex)==6)
        {
            p.setRenderHint( QPainter::Antialiasing, true );     //抗锯齿
            p.setBrush(circle_vector.at(circle_index).bg_color); //++设置填充色
            pen.setColor(circle_vector.at(circle_index).pen_color);
            pen.setStyle(circle_vector.at(circle_index).pen_style);
            pen.setWidth(circle_vector.at(circle_index).pen_size);
            p.setPen(pen);
            int xlen=circle_vector.at(circle_index).end_point.x()-circle_vector.at(circle_index).start_point.x();
            int ylen=circle_vector.at(circle_index).end_point.y()-circle_vector.at(circle_index).start_point.y();
            int len=qSqrt(abs(xlen*xlen)+abs(ylen*ylen));
            p.drawEllipse(circle_vector.at(circle_index).start_point,len,len);
            ++circle_index;
        }
        else if(drawtype_vector.at(typeindex)==7){
            p.setRenderHint( QPainter::Antialiasing, true );    //抗锯齿
            pen.setStyle(brokenline_vector.at(broken_index).pen_style);
            pen.setColor(brokenline_vector.at(broken_index).pen_color);
            pen.setWidth(brokenline_vector.at(broken_index).pen_size);
            p.setPen(pen);
            const QVector<QPoint> & points=brokenline_vector.at(broken_index).point_vector;
            for(int i=0;i<points.size()-1;++i)
            {
                p.drawLine(points.at(i),points.at(i+1));
            }
            ++broken_index;
        }
        else if(drawtype_vector.at(typeindex)==8)
        {
            p.setRenderHint( QPainter::Antialiasing, true );    //抗锯齿
            pen.setStyle(_text.at(text_index).pen_style);
            pen.setColor(_text.at(text_index).pen_color);
            pen.setWidth(_text.at(text_index).pen_size);
            p.setPen(pen);
            p.drawText(_tpoint.at(text_index),_text.at(text_index).text_str);
            text_index++;
        }
        else if(drawtype_vector.at(typeindex)==9)
        {
            p.setRenderHint( QPainter::Antialiasing, true );    //抗锯齿
        }
    }
    p.end();
    p.begin(this);         //将当前窗体作为画布
    p.drawPixmap(0,0, pix);//将pixmap画到窗体
}
