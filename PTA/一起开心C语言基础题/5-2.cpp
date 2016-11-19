#include <iostream>
using namespace std;
double fact(int n);
int main()
{
	int m, n;
	cin >> m >> n;
	double ans = fact(n) / (fact(m) * fact(n - m));
	cout << "result = " << ans;
	return 0;
} 
double fact(int n)
{
	double result = 1;
	for(int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
