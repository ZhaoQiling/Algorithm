#include <iostream>
using namespace std;
bool isUsed[25];
int ans[25];
int total;
int nSol;
void dfs(int order);
bool isPrime(int num);
int main(int argc, char **argv)
{
    nSol = 1;
    while(cin >> total)
    {
        ans[1] = 1;
        isUsed[1] = true;
        cout << "Case " << nSol << ":" << endl;
        dfs(2);
        cout << endl;
        nSol++;
    }
    return 0;
}
void dfs(int order)
{
    for(int i = 1; i <= total; i++)
    {
        if(isUsed[i] == true)
            continue;
        if(isPrime(i + ans[order - 1]))
        {
            ans[order] = i;
            isUsed[i] = true;
            dfs(order + 1);
            isUsed[i] = false;
            if(order == total)
            {
                if(!isPrime(ans[order] + 1))
                    continue;
                for(int i = 1; i <= total; i++)
                {
                    cout << ans[i];
                    if(i != total) cout << " ";
                }
                cout << endl;
            }
        }
    }
}
bool isPrime(int num)
{
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}