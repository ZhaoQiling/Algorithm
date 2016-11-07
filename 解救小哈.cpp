#include <iostream>
using namespace std;
int startX, startY;
int endX, endY;
int row, col;
int mins = 99999;
bool isVisit[100][100];
int next[4][2] ={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int x, int y, int step, string *board);
int main()
{
    cin >> row >> col;
    string *board = new string[row];
    for(int i = 0; i < row; i++)
    {
        cin >> board[i];
    }
    cin >> startX >> startY;
    cin >> endX >> endY;
    isVisit[startX][startY] = true;
    startX--; startY--; 
    endX--; endY--;
    dfs(startX, startY, 0, board);
    if(mins == 99999)
    {
        cout << "No Way!" << endl;
    }
    else
    {
        cout << mins << endl;
    }
    return 0;
}

void dfs(int x, int y, int step, string *board)
{
 //   cout << x << y << step << endl;
    if(x == endX && y == endY)
    {
        if(step < mins)
        {
            mins = step;
        }
        return;
    }
    for(int i = 0; i <= 3; i++)
    {
        int dx = next[i][0];
         int dy = next[i][1];
        if(x + dx >= row || x + dx < 0 || y + dy >= col || y + dy < 0)
        {
            continue;
        }
        if(board[x + dx][y + dy] == '0' && isVisit[x + dx][y + dy] == false)
        {
            isVisit[x + dx][y + dy] = true;
            dfs(x + dx, y + dy, step + 1, board);
            isVisit[x + dx][y + dy] = false;
        }
    }
 

}