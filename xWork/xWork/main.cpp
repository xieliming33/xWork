#include "mainwindow.h"
#include <QTextCodec>
#include <QApplication>
#include <QDesktopWidget>
/*
 *  xWork 2019.07.5 xieliming
 */
int main(int argc, char *argv[])
{
    //避免中文乱码
    QTextCodec* codec=QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //窗口居中显示
    w.move((QApplication::desktop()->width()-w.width())/2,(QApplication::desktop()->height()-w.height())/2);
    return a.exec();
}
