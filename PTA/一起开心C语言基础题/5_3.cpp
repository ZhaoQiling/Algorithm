#include <stdio.h>
#include <math.h>
//#include <iostream>
//using namespace std; 
bool isPrime(int number);
int main()
{
	int N;
	scanf("%d", &N);
	int count = 0;
	for(int i = 2; i < N; i++)
	{
		if(isPrime(i) && isPrime(i + 2))
		{
			count++;
//			cout << i << " " << i + 2 << endl;
		}
	}
	printf("%d", count);
	return 0;
} 
bool isPrime(int number)
{
	for(int i = 2; i < sqrt(number) + 1; i++)
	{
		if(number % i == 0)
			return false;
	}
	return true;
} 
