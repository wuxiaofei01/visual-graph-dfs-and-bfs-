#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QMessageBox>
#include<QPainter>
#include"bfs.h"
#include"dfs.h"
#include"window.h"
#include<QMovie>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("图的遍历");


}

MainWindow::~MainWindow()
{
    delete ui;

}


int MainWindow::isDigitStr(QString src)
{

    QByteArray ba = src.toLatin1();//QString 转换为 char*
    const char *s = ba.data();
    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return 0;
    }
    else
    { //纯数字
        return 1;
    }
}
void MainWindow::on_lineEdit_cursorPositionChanged()//节点数量
{
    nodes=ui->lineEdit->text();
    QMessageBox msg(this);//对话框设置父组件
    msg.setWindowTitle("input is not invailid");//对话框标题
    msg.setText("This is a wrong input!");//对话框提示文本
    msg.setIcon(QMessageBox::Information);//设置图标类型
    msg.setStandardButtons(QMessageBox::Ok );//对话框上包含的按钮

    int flag=isDigitStr(nodes);


    if((flag==0||nodes.size()>1)&&msg.exec() == QMessageBox::Ok)//模态调用
    {
       qDebug() << " Ok is clicked!";//数据处理
    }
}

void MainWindow::on_lineEdit_2_cursorPositionChanged()//起点字符串
{
    from=ui->lineEdit_2->text();

}

void MainWindow::on_lineEdit_3_cursorPositionChanged()//终点字符串
{
    to=ui->lineEdit_3->text();


}
int MainWindow::check()
{

    QMessageBox msg(this);//对话框设置父组件
    msg.setWindowTitle("input is not invailid");//对话框标题
    msg.setText("the input is ont invailide!");//对话框提示文本
    msg.setIcon(QMessageBox::Information);//设置图标类型
    msg.setStandardButtons(QMessageBox::Ok );//对话框上包含的按钮


    if((isDigitStr(to)==0||to.size()!=from.size()||isDigitStr(from)==0)&&msg.exec() == QMessageBox::Ok)//模态调用
    {

       qDebug() << from.length()<<to.length();//数据处理
       return 0;
    }

    return 1;
}
int MainWindow::check(int size)
{
    if(size!=nodes.toInt())
    {
        QMessageBox msg(this);//对话框设置父组件
        msg.setWindowTitle("input is not invailid");//对话框标题
        msg.setText("the input is too much");//对话框提示文本
        msg.setIcon(QMessageBox::Information);//设置图标类型
        msg.setStandardButtons(QMessageBox::Ok );//对话框上包含的按钮


        if(msg.exec() == QMessageBox::Ok)//模态调用
        {

           qDebug() << from.length()<<to.length();//数据处理
           return 0;
        }
        return 0;
    }
    return 1;
}
void MainWindow::on_pushButton_clicked()//dfs按钮
{

    if(check()==0) return;//不合法
    DFS a(nodes,from,to);
    if(check(a.size)==0)return;
    this->hide();
    DfsShow* newshow=new DfsShow;
    newshow->setWindowTitle("深度优先优先搜索");
    newshow->start(a.order_traverse,nodes.toInt());//传参数 得到路径 和 点的数量
}



void MainWindow::on_pushButton_2_clicked()//bfs按钮
{
    if(check()==0) return;//不合法
    bfs a(from,to);
    if(check(a.size)==0)return;
    this->hide();
    DfsShow* newshow=new DfsShow;
    newshow->setWindowTitle("广度优先优先搜索");
    newshow->start(a.result,nodes.toInt());//传参数 得到路径 和 点的数量

}
