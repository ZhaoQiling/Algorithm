#include <iostream>
using namespace std;
struct Node{
    int floor;
    int row;
    int col;
    int step;
};
char dungeon[35][35][35];
bool isVisit[35][35][35];
Node que[27100];
int next[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1},{0, 1, 0}, {0, -1, 0} };
int main(int argc, char **argv)
{
    int nFloor, nRow, nCol;
    cin >> nFloor >> nRow >> nCol;
    int start[3];
    
    while(nFloor != 0)
    {
        int sum = -1;
        for(int i = 1; i <= nFloor; i++)
            for(int j = 1; j <= nRow; j++)
                for(int k = 1; k <= nCol; k++)
                {
                    isVisit[i][j][k] = false;
                    cin >> dungeon[i][j][k];
                    if(dungeon[i][j][k] == 'S')
                    {
                        start[0] = i;
                        start[1] = j;
                        start[2] = k;
                    }
                }
                    
        int head = 1;
        int tail = 1;
        que[head].step = 0;
        que[tail].floor = start[0];
        que[tail].row = start[1];
        que[tail].col = start[2];
        isVisit[start[0]][start[1]][start[2]] = true;
        tail++;
        while(head < tail)
        {
            int floor = que[head].floor;
            int row = que[head].row;
            int col = que[head].col;
            for(int i = 0; i < 6; i++) //向上下左右前后扩展
            {
                int dFloor = next[i][0];
                int dRow = next[i][1];
                int dCol = next[i][2];
                if(dFloor + floor <= 0 || dFloor + floor > nFloor || dRow + row <= 0 || dRow + row > nRow || dCol + col <= 0 || dCol + col > nCol)
                    continue;
                if(isVisit[dFloor + floor][dRow + row][dCol + col] == true || dungeon[dFloor + floor][dRow + row][dCol + col] == '#')
                    continue;
    //            cout << dFloor + floor << dRow + row << dCol + col << endl;
                isVisit[dFloor + floor][dRow + row][dCol + col] = true;
                que[tail].floor = dFloor + floor;
                que[tail].row = dRow + row;
                que[tail].col = dCol + col;
                que[tail].step = que[head].step + 1;
                if(dungeon[dFloor + floor][dRow + row][dCol + col] == 'E')
                    sum = que[tail].step;
                tail++;
            }
            head++;
        }
        
        if(sum < 0) cout << "Trapped!" << endl;
        else cout << "Escaped in "<< sum <<" minute(s)." << endl;
        
        cin >> nFloor >> nRow >> nCol;
    }
    
    return 0;
}
