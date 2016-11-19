#include <iostream>
using namespace std;
const int arrSize = 21;
int main()
{
	int arrSize1, arrSize2;
	int ans[arrSize];
	int inter[arrSize];
	int arr1[arrSize];
	int arr2[arrSize];

	cin >> arrSize1; 
	for(int i = 1; i <= arrSize1; i++)
		cin >> arr1[i];

	cin >> arrSize2;
	for(int i = 1; i <= arrSize2; i++)
		cin >> arr2[i];
	int flag = 1;
	for(int i = 1; i <= arrSize1; i++)
	{
		for(int j = 1; j <= arrSize2; j++)
		{
			if(arr1[i] == arr2[j])
			{
				inter[flag] = arr1[i];
				flag++;
			}
		}
	}
	int where = 1;
	for(int i = 1; i <= arrSize1; i++)
	{
		for(int j = 1; j < flag; j++)
		{
			if(arr1[i] == inter[j]) break;
			if(j == flag - 1) 
			{
				ans[where] = arr1[i];
				where++;
			}
		}
	}

	for(int i = 1; i <= arrSize2; i++)
	{
		for(int j = 1; j < flag; j++)
		{
			if(arr2[i] == inter[j]) break;
			if(j == flag - 1) 
			{
				ans[where] = arr2[i];
				where++;
			}
		}
	}
	where--;
	
	int output[arrSize];
	int nOutput = 1;
	for(int i = 1; i <= where; i++)
	{
		bool isRe = false;
		for(int j = 1; j < i; j++)
		{
			if(ans[j] == ans[i])
			{
				isRe = true;
				break;
			}
		}
		if(isRe == false)
		{
			output[nOutput] = ans[i];
			nOutput++;
		}
	}
	nOutput--;
	
	for(int i = 1; i < nOutput; i++) 
		cout << output[i] << " ";
	cout << output[nOutput];
	return 0;
} 
