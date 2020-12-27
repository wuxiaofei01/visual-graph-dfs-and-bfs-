#include "window.h"
#include "ui_dfsshow.h"
#include "mainwindow.h"
#include <QPainter>
#include <iostream>
#include <vector>
#include <queue>
#include <QPainter>
#include<cmath>
DfsShow::DfsShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DfsShow)
{
    ui->setupUi(this);
    this->show();
    pos=0;
    init();
}

DfsShow::~DfsShow()
{
    delete ui;
}
void DfsShow::drawArrow(QPoint startPoint, QPoint endPoint, QPainter &p)
{
    double par = 15.0;//箭头部分三角形的腰长
    double slopy = atan2((endPoint.y() - startPoint.y()), (endPoint.x() - startPoint.x()));
    double cosy = cos(slopy);
    double siny = sin(slopy);
    QPoint point1 = QPoint(endPoint.x() + int(-par*cosy - (par / 2.0*siny)), endPoint.y() + int(-par*siny + (par / 2.0*cosy)));
    QPoint point2 = QPoint(endPoint.x() + int(-par*cosy + (par / 2.0*siny)), endPoint.y() - int(par / 2.0*cosy + par*siny));
    QPoint points[3] = { endPoint, point1, point2 };
    p.setRenderHint(QPainter::Antialiasing, true);//消锯齿
    QPen drawTrianglePen;//创建画笔
    drawTrianglePen.setColor(Qt::red);
    drawTrianglePen.setWidth(1);
    p.setPen(drawTrianglePen);
    p.drawPolygon(points, 3);//绘制箭头部分
    int offsetX = int(par*siny / 3);
    int offsetY = int(par*cosy / 3);
    QPoint point3, point4;
    point3 = QPoint(endPoint.x() + int(-par*cosy - (par / 2.0*siny)) + offsetX, endPoint.y() + int(-par*siny + (par / 2.0*cosy)) - offsetY);
    point4 = QPoint(endPoint.x() + int(-par*cosy + (par / 2.0*siny) - offsetX), endPoint.y() - int(par / 2.0*cosy + par*siny) + offsetY);
    QPoint arrowBodyPoints[3] = { startPoint, point3, point4 };
    p.drawPolygon(arrowBodyPoints, 3);//绘制箭身部分
}

void DfsShow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    //drawArrow(QPoint(100,100),QPoint(700,700),painter);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 设置画笔颜色
    painter.setPen(QColor(0, 160, 230));
    // 绘制圆

    for(int i=0;i<pos;i+=2)//找到需要画的边和点   画线段
    {
        char from=path[i],to=path[i+1];
        for(int j=1;j<=nodes;j++)
        {
            if(from==name[j]) visit[j]=1;
            if(to  ==name[j]) visit[j]=1;
        }
    }

    for(int i=1;i<=nodes;i++)
    {
        QColor color;
        if(visit[i]==1) color = Qt::yellow;
        else color=Qt::white;
        painter.setPen(QPen(QBrush(color), 2));

        painter.setBrush(color);

        painter.drawEllipse(point[i],35,35);


        painter.setFont(QFont("system", 12, 700));//字体部分
        painter.setPen(Qt::black);
        char s[10];
        s[0]=name[i];
        s[1]='\0';
        painter.drawText(point[i].x(),point[i].y(),s);//绘制文本 QTextOption(Qt::AlignCenter));//中心对齐
    }
        painter.setBrush(Qt::red);
    for(int i=0;i<pos;i+=2)//找到需要画的边和点   画线段
    {
        char from=path[i],to=path[i+1];
        QPoint node1,node2;
        for(int j=1;j<=nodes;j++)
        {
            if(from==name[j]) node1=point[j],visit[j]=1;
            if(to  ==name[j]) node2=point[j],visit[j]=1;
        }
        //painter.drawLine(node1,node2);
        node2.rx()=node2.x()-15;
        node2.ry()=node2.y()-15;
        if(node1.x()!=node2.x()+15)
        drawArrow(node1,node2,painter);


    }


}

void DfsShow::start(QString root,int number)//最开始的初始化 数据函数
{
    path=root.toStdString();
    nodes=number;
    int pos=1;
    char temp[10];//记录出现的位置

    for(int i=1;i<=10;i++)temp[i]='0';//初始化都没有访问过

    for(int i=0;i<root.length();i++)//长度相同
    {
        if(temp[path[i]-'0']=='0')name[pos++]=path[i],temp[path[i]-'0']='1';
    }

    update();//重绘
}
void DfsShow::init()
{
    for(int i=1;i<=9;i++)visit[i]=0;//初始化 未被访问
    point[1].rx()=515,point[1].ry()=50;

    point[2].rx()=975,point[2].ry()=320;

    point[3].rx()=705,point[3].ry()=600;

    point[4].rx()=305,point[4].ry()=600;

    point[5].rx()=55,point[5].ry()=300;

    point[6].rx()=210,point[6].ry()=120;

    point[7].rx()=820,point[7].ry()=120;

    point[8].rx()=900,point[8].ry()=540;

    point[9].rx()=130,point[9].ry()=540;
}
void DfsShow::on_pushButton_clicked()
{
    pos+=2;//得到当前应该访问哪一个节点了
    update();
}

void DfsShow::on_pushButton_2_clicked()
{
    MainWindow* window=new MainWindow;
    this->hide();
    window->show();
}
