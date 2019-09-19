#ifndef PARAMSWIDGET_H
#define PARAMSWIDGET_H

#include <QObject>
#include <QWidget>

#include <QDebug>
#include <QAction>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QPushButton>

class ParamsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ParamsWidget(QWidget *parent = 0);
    void InitFunc();
    void ConnectFunc();
signals:
    void SetDrawTypeFlagSignal(int);
    void SetPenColorSignal(QColor );
    void SetBgColorSignal(QColor);
    void SetPenSizeSignal(int );
    void SetPenTypeSignal(int );
public slots:
    void CurrentIndexSlots(int index);
    void CurrentIndexPenTypeSlots(int index);
    void PenWidthCurindexSlots(int index);
    void PenColorCurIndexSlots();
    void BackgroundColorSlots();
    void DefaultParamBtnSLots();
private:
    QLabel* drawtype_label;
    QComboBox* drawtype_combox;          //画图类型
    QLabel* pentype_label;               //画笔类型
    QComboBox* pentype_combox;
    QLabel* penwidth_label;              //线宽大小
    QComboBox* penwidth_combox;
    QLabel* pencolor_label;              //画笔颜色
    QComboBox* pencolor_combox;
    QLabel* bgcolor_label;               //填充颜色
    QComboBox* gbcolor_combox;

    QPushButton* defaultparam_btn;

    int colorlist_size;
};

#endif // PARAMSWIDGET_H
