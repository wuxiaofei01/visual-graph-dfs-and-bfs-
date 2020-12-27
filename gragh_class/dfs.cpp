#include "dfs.h"
#include "algorithm"
#include "vector.h"
#include "pair.h"
#include "QByteArray"

DFS::DFS(QString nodes, QString _from, QString _to):size(nodes.toInt()), nodeFrom(_from),nodeTo(_to)
{

    makeSuit();     //根据输入数据进行调整/初始化

    //检查输入合法性  实际顶点个数不超过nodes值
    if(!isLegal())
        return;

    buildGraph();   //建图

    for(int i=1; i<=10 ;i++){ //图不连通
        if(!vis[i] && Graph[i].size()){
            dfs(i, i);
        }
    }

   qDebug() << order_traverse << " " << order_edges;

}

void DFS::makeSuit(void) //根据输入数据进行调整/初始化
{
    //QString 转 std::string
    from = nodeFrom.toUtf8().constData();
    to = nodeTo.toUtf8().constData();

    //初始化
    vis.resize(15);
    for(int i=0;i<vis.size();i++)
        vis[i] = 0;
    orderBYedges.resize(15);

    for (int i=0;i<=10;i++)
        orderBYedges[i].first = i;

}

int DFS::isLegal(void)
{
   Vector<int> digits(11);
   for(int i=0;i<digits.size();i++)
       digits[i] = 0;
   for(auto &c : from)
       digits[c-'0'] = 1;
   for(auto &c : to)
       digits[c-'0'] = 1;
   int cnt = 0;
   for(int i=1;i<=9;i++)
       if(digits[i])
           cnt++;
   if(cnt != size)
   {
       size=cnt;
       msg = "输入顶点数与实际顶点数不相符";
       legalFlag = 0;
   }
   else
   {
       msg = "没问题";
       legalFlag = 1;
   }

   return legalFlag;
}

void DFS::buildGraph(void)//建图
{

    int m = nodeFrom.length();

    for (int i = 0; i < m; i++)
    {   //每个节点保证是数字字符
        Graph[from[i] - '0'].push_back(to[i] - '0');  //无向图
        Graph[to[i]- '0'].push_back(from[i] - '0');


        //记录度
        orderBYedges[from[i] - '0'].second++;
        orderBYedges[to[i] - '0'].second++;
    }


    std::sort(orderBYedges.begin() , orderBYedges.begin() + orderBYedges.size() ,[&](Pair<int,int> &a,Pair<int,int> &b){
        return a.second > b.second;
    });//依节点的度降序排列s

    for(int i=0;i<size;i++)
        order_edges += QString::number(orderBYedges[i].first) + QString::number(orderBYedges[i].second);

}

void DFS::dfs(int v, int fa)//进行深度优先遍历
{
    if(vis[v])
        return;
    vis[v] = 1;

    //记录遍历顺序
    orderBYtraverse.push_back({fa, v});
    order_traverse += QString::number(fa) + QString::number(v);

    for (int i = 0; i < Graph[v].size(); i++)
    {
        if(!vis[Graph[v][i]])
        {
            dfs(Graph[v][i], v);
        }
    }
}
