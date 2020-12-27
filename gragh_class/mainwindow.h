#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString nodes;//节点的数量
    QString from,to;//开始和结束点

    int isDigitStr(QString src);//判断是不是纯数字

    void draw(QPainter& p,int i);//画圆的编号

    int check();//检查输入是否合法
    int check(int size);

private slots:
    void on_lineEdit_cursorPositionChanged();

    void on_lineEdit_2_cursorPositionChanged();

    void on_lineEdit_3_cursorPositionChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
