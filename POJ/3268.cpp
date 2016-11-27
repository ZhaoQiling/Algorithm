#include <iostream>
using namespace std;
const int inf = 999999;
int graph[1010][1010];
int isVisit[2][1010];
int dis[2][1010];
int main()
{
    int nFarm, nRoad, partyPlace;
    cin >> nFarm >> nRoad >> partyPlace;
    
    //初始化graph
    for(int i = 1; i <= nFarm; i++)
    {
        for(int j = 1; j <= nFarm; j++)
        {
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = inf;
        }
    }
    //输入graph
    for(int i = 1; i <= nRoad; i++)
    {
        int x, y;
        cin >> x >> y;
        cin >> graph[x][y];
    }
    //初始化dis[0][]
    for(int i = 1; i <= nFarm; i++)
    {
        dis[0][i] = graph[partyPlace][i];
    }
    //
    isVisit[0][partyPlace] = true;
    for(int i = 1; i <= nFarm - 1; i++)
    {
        int min = inf;
        int u, v;
        for(int j = 1; j <= nFarm; j++)
        {
            if(dis[0][j] < min && isVisit[0][j] == false)
            {
                min = dis[0][j];
                u = j;
            }
        }
        isVisit[0][u] = true;
        for(v = 0; v <= nFarm; v++)
        {
            if(graph[u][v] >= inf)
                continue;
            if(dis[0][u] + graph[u][v] < dis[0][v])
                dis[0][v] = dis[0][u] + graph[u][v];
        }
    }
    //翻转图
    for(int i = 1; i <= nFarm; i++)
    {
        for(int j = i; j <= nFarm; j++)
        {
            int t;
            t = graph[i][j];
            graph[i][j] = graph[j][i];
            graph[j][i] = t;
        }
    }
    
    //初始化dis[1][]
    for(int i = 1; i <= nFarm; i++)
    {
        dis[1][i] = graph[partyPlace][i];
    }
    
    isVisit[1][partyPlace] = true;
    for(int i = 1; i <= nFarm - 1; i++)
    {
        int min = inf;
        int u, v;
        for(int j = 1; j <= nFarm; j++)
        {
            if(dis[1][j] < min && isVisit[1][j] == false)
            {
                min = dis[1][j];
                u = j;
            }
        }
        isVisit[1][u] = true;
        for(v = 0; v <= nFarm; v++)
        {
            if(graph[u][v] >= inf)
                continue;
            if(dis[1][u] + graph[u][v] < dis[1][v])
                dis[1][v] = dis[1][u] + graph[u][v];
        }
    }
    
//    for(int i = 1; i <= nFarm; i++)
//        cout << dis[0][i] << " ";
//    cout << endl;
//    for(int j = 1; j <= nFarm; j++)
//        cout << dis[1][j] << " ";
    int sum = 0;
    for(int i = 1; i <= nFarm; i++)
    {
        if(sum < dis[0][i] + dis[1][i])
            sum = dis[0][i] + dis[1][i];
    }
    cout << sum;
    return 0;
}