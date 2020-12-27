#ifndef BFS_H
#include"QString"
#define BFS_H


class bfs
{
public:
    bfs(QString& form,QString& to);
    void do_bfs(int data[][20],int root);
    int info[20],value[20];
    QString result;
    int size=0,tag=0,count=0;
};

#endif // BFS_H
