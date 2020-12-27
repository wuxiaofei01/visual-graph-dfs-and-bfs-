#include "bfs.h"
#include"QString"
#include"string"
#include"QQueue"
bfs::bfs(QString& form,QString& to)
{
    QByteArray form_QB = form.toLatin1();
    char *form_ch = form_QB.data();
    QByteArray to_QB = to.toLatin1();
    char *to_ch = to_QB.data();                     //把QString类型转化为char类型
    int i,length_to=to.size(),j,data[20][20];
    int root=form_ch[0]-'0';
    int set[20];
    for(int i=0;i<20;i++){                  //初始化set
        set[i]=0;
    }
    for(int i=0;i<length_to;i++){           //计算一共有多少个不同的数
        if(set[form_ch[i]-'0']==0){
            set[form_ch[i]-'0']=1;
            size++;
        }
        if(set[to_ch[i]-'0']==0){
            set[to_ch[i]-'0']=1;
            size++;
        }
    }
    for(i=0;i<20;i++){                      //info表示这个点是否被访问
        info[i]=0;
    }
    for(i=0;i<20;i++){                      //采用矩阵储存数据，并先对其进行初始化
        for(j=0;j<20;j++)
            data[i][j]=0;
    }
    i=0;
    data[19][19]=length_to;
    while(1){                               //将输入的数据传入data矩阵中，并且默认自己与自己相连（后面有用）
        if(i<length_to){
            int num_form=form_ch[i]-'0',num_to=to_ch[i]-'0';
            data[num_form][num_to]=1;
            data[num_to][num_form]=1;
            data[num_to][num_to]=1;             //自己与自己相连
            data[num_form][num_form]=1;
            i++;
            continue;
        }
        else{
            break;
        }
    }
    //bfs，因为画图时要从根节点开始，所有进行此次
    do_bfs(data,root);
    if(tag==0){
        QString trash=QString::number(root);
        trash+=trash;
        trash+=result;
        result=trash;
    }
    tag=0;
    for(int i=0;i<20;i++){              //对非连通图进行操作
        if(info[i]==0&&set[i]==1){
            result+=QString::number(i);
            result+=QString::number(i);
            do_bfs(data,i);
        }
    }

}
void bfs::do_bfs(int data[][20],int root){
    QQueue<int> Q;
        if (info[root] == 0) {
            info[root] = 1;
            int flag=0;
            for (int i = 0; i < 20; i++) {
                if (data[root][i] == 1&&root!=i) {          //保证不是自己与自己
                    Q.enqueue(i);
                    result+=QString::number(root);
                    result+=QString::number(i);
                    info[i] = 1;
                    flag=1;
                    count++;
                }
            }
            if(flag==0&&data[root][root]==1){               //将只有自己与自己的情况列入
                result+=QString::number(root);
                result+=QString::number(root);
                tag=1;
                count++;
            }
        }

        while (!Q.isEmpty()) {
            int num;
            num = Q.dequeue();
            for (int i = 0; i < 20; i++) {
                if (data[num][i] == 1&&info[i]==0&&num!=i) {
                    Q.enqueue(i);
                    info[i] = 1;
                    result+=QString::number(num);
                    result+=QString::number(i);
                    count++;
                }
            }
        }
}
