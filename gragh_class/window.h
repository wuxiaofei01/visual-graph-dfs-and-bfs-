#ifndef DFSSHOW_H
#define DFSSHOW_H

#include <QMainWindow>

namespace Ui {
    class DfsShow;
}

class DfsShow : public QWidget{
    Q_OBJECT
public:
    explicit DfsShow(QWidget *parent = 0);
    ~DfsShow();

    void start(QString root,int nummber);
    void init();//初始化坐标
    void drawArrow(QPoint startPoint, QPoint endPoint, QPainter &p);

    QPoint point[10];//依次顺序的点坐标

    std::string path;

    int visit[10];//标记数组
    int nodes;
    int pos;//记录要画的边 到哪了

    char name[10];//对应点的标号

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DfsShow *ui;
    void paintEvent(QPaintEvent *);


};

#endif // BP_H
