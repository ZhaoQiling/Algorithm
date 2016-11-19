#include <iostream>
#include <cmath>
using namespace std;
int arr[101];
int main()
{
	int arrSize, nMove;
	cin >> arrSize >> nMove;
	for(int i = 1; i <= arrSize; i++)
	{
		cin >> arr[i];
	}
	int head = 1;
	for(int i = 1; i <= nMove; i++)
	{
		head--;
		if(head <= 0) head = arrSize;
	} 
	for(int i = 1; i < arrSize; i++)
	{
//		cout << "head" << head << " = ";
		cout << arr[head] << " ";
		head++;
		if(head == arrSize + 1)
		{
			head = 1;
		}
	}
	cout << arr[head];
	return 0;
} 
