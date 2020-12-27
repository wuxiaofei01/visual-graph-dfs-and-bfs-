#ifndef DFS_H
#define DFS_H
#include"QString"
#include"vector.h"
#include"pair.h"
class DFS
{
public:
    DFS(QString nodes, QString _from, QString _to);
    int size;
    int legalFlag;  //1合法，0不合法
    QString nodeFrom, nodeTo;
    QString msg;    //错误信息
    QString order_edges, order_traverse;

private:

    void buildGraph(void);  //建图

    //对应nodeFrom,nodeTo
    std::string from, to;

    Vector<int> Graph[20], vis; //图和访问数组  !初始化大小

    void dfs(int v, int fa);    //深搜

    Vector<Pair<int, int>> orderBYtraverse, orderBYedges;

    void makeSuit(void);    //根据输入数据进行调整/初始化

    int isLegal(void);  //检查输入合法性
};

#endif // DFS_H
