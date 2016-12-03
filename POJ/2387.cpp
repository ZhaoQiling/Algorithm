#include <iostream>
using namespace std;
const int arrSize = 1010;
const int inf = 9999999;
int graph[arrSize][arrSize];
int dis[arrSize];
bool isVisit[arrSize];
int main()
{
//Landmark 1 is the barn;
//the apple tree grove in which Bessie stands all day is landmark N.
    int nLandmark, nRoad;
    cin >> nRoad >> nLandmark;
    for(int i = 1; i <= nLandmark; i++)
        for(int j = 1; j <= nLandmark; j++)
            graph[i][j] = inf;

    for(int i = 1; i <= nRoad; i++)
    {
        int x, y;
        int val;
        cin >> x >> y;
        cin >> val;
        if(val < graph[x][y])
            graph[y][x] = graph[x][y] = val;
    }

    isVisit[1] = true;
    for(int i = 1; i <= nLandmark; i++)
        dis[i] = graph[1][i];

    for(int i = 1; i < nLandmark; i++)
    {
        int min = inf;
        int u;
        for(int j = 1; j <= nLandmark; j++)
        {
            if(isVisit[j] == false && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }
        isVisit[u] = true;
        for(int v = 1; v <= nLandmark; v++)
        {
            if(graph[u][v] >= inf)
                continue;
            if(dis[u] + graph[u][v] < dis[v])
                dis[v] = dis[u] + graph[u][v];
        }
    }

    cout << dis[nLandmark] << endl;
    return 0;
}
