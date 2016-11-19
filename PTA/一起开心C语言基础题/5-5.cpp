#include <stdio.h>
int nNumber[8];
int fact(int, int);
int main()
{
    int n;
    scanf("%d", &n);

    for(int i = fact(10, n - 1); i <= fact(10, n) - 1; i++)
    {
		int change = i;
		for(int j = n; j >= 1; j--)
		{
			nNumber[j] = change % 10;
			change /= 10;
		}
		int sum = 0;
		for(int j = 1; j <= n; j++)
		{
			sum += fact(nNumber[j], n);
		}
		if( i == sum)
		{
			printf("%d\n", i);
		}
    }
}
int fact(int number, int n)
{
    int sum = 1;
    for(int i = 1; i <= n; i++)
        sum *= number;
    return sum;
}

