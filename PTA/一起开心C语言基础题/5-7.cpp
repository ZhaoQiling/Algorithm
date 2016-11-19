#include <iostream>
using namespace std;
int main()
{
	int sumOfBoard = 0;
	int sumOfLastRow = 0;
	int sumOfLastCol = 0;
	int sumOfDiagonal = 0;
	const int arrSize = 11;
	int board[arrSize][arrSize];
	int length;
	cin >> length;
	for(int i = 1; i <= length; i++)
	{
		for(int j = 1; j <= length; j++)
		{
			int val;
			cin >> val;
			board[i][j] = val;
			sumOfBoard += val;
			if(i == length) sumOfLastRow += val;
			if(j == length) sumOfLastCol += val;
			if(length + 1 == i + j) sumOfDiagonal += val;
		}
	}
	cout << sumOfBoard 
			- sumOfLastRow - sumOfLastCol - sumOfDiagonal
			+ board[1][length] + board[length][1] + board[length][length];
	return 0;
} 
