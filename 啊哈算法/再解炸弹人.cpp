#include <iostream>
#include <stdio.h>
using namespace std;
struct Node{
    int x;
    int y;
};
int row, col;
int ansNum, ansX, ansY;
char board[50][50];
bool isVisit[50][50];
int getNum(int x, int y);
int main()
{
    int startX, startY;
    Node queue[2501];
    int next[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int head = 1;
    int tail = 1;
    cin >> row >> col >> startX >> startY;
    for(int i = 0; i < row; i++)
    {
        scanf("%s", board[i]);
    }
    queue[tail].x = startX;
    queue[tail].y = startY;
    isVisit[startX][startY] = true;
    ansNum = getNum(startX, startY);
    ansX = startX;
    ansY = startY;
    tail++;
    while(head < tail)
    {
        for(int i = 0; i <= 3; i++)
        {
            int tx = queue[head].x + next[i][0];
            int ty = queue[head].y + next[i][1];
            if(tx < 0 || tx >= row || ty < 0 || ty >= col)
                continue;
            if(board[tx][ty] == '.' && isVisit[tx][ty] == false)
            {
                isVisit[tx][ty] = true;
                queue[tail].x = tx;
                queue[tail].y = ty;
                tail++;
                
                int sum = getNum(tx, ty);
                if(sum > ansNum)
                {
                    ansNum = sum;
                    ansX = tx;
                    ansY = ty;
                }
            }
        }
        head++;
    }
    cout << ansNum; //<< " at " << ansX << ", " << ansY << endl;
    return 0;
}
int getNum(int x, int y)
{
    //向上计数
    int sum = 0;
    for(int i = x; i >= 0; i--)
    {
        if(board[i][y] == '.')
            continue;
        else if(board[i][y] == 'G')
            sum++;
        else
            break;
    }
    //向下计数
    for(int i = x; i < row; i++)
    {
         if(board[i][y] == '.')
            continue;
        else if(board[i][y] == 'G')
            sum++;
        else
            break;
    }
    //向左计数
    for(int i = y; i >= 0; i--)
    {
        if(board[x][i] == '.')
            continue;
        else if(board[x][i] == 'G')
            sum++;
        else
            break;
    }
    //向右计数
    for(int i = y; i < col; i++)
    {
        if(board[x][i] == '.')
            continue;
        else if(board[x][i] == 'G')
            sum++;
        else
            break;
    }
    return sum;
}