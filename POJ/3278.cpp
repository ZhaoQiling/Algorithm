#include <iostream>
using namespace std;
struct Node
{
    int x;
    int step;
};
int start, end;
int ans = 100010;
const int arrSize = 100010;
Node line[arrSize];
bool isVisit[arrSize];
void compare(int flag)
{
    if(line[flag].x == end)
    {
        
        if(ans > line[flag].step)
        {
            ans = line[flag].step;
        }
       // cout << "Comparing" << ans <<endl;
    }
}
int main(int argc, char **argv)
{
    cin >> start >> end;
    int head = 1;
    int tail = 1;
    isVisit[start] = true;
    line[tail].x = start;
    tail++;
    if(start == end)
    {
        cout << 0;
        return 0;
    }
    while(head < tail)
    {
        //分别尝试三种不同的方法
        for(int i = 0; i < 3; i++)
        {
            if(i == 0)// X + 1 的移动方式
            {
                int t = line[head].x + 1;
                if(t > 100000)
                    continue;
                if(isVisit[t] == false)//入队操作
                {
                    isVisit[t] = true;
                    line[tail].x = t;
                    line[tail].step = line[head].step + 1;
                    compare(tail);
                    tail++;
                }
            }
            
            if(i == 1)// X - 1的移动方式
            {
                int t = line[head].x - 1;
                if(t < 0)
                    continue;
                if(isVisit[t] == false)
                {
                    isVisit[t] = true;
                    line[tail].x = t;
                    line[tail].step = line[head].step + 1;
                    compare(tail);
                    tail++;
                }
            }
            
            if(i == 2)
            {
                int t = line[head].x * 2;
                if(t > 100000)
                    continue;
                if(isVisit[t] == false)
                {
                    isVisit[t] = true;
                    line[tail].x = t;
                    line[tail].step = line[head].step + 1;//这里step要加上head的step而不是自己的step++ !!!
                    compare(tail);
                    tail++;
                }
            }
        }
        head++;
    }
    cout << ans << endl;
    return 0;
}
