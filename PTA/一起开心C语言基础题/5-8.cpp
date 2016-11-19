#include <iostream>
#include <stack>
using namespace std;
string input;
int main()
{
	cin >> input;
	int head = 0;
	int tail = 0;
	char opt = '$'; //��ʼ��opt������������֮���ж��Ƿ���������� 
	for(int i = 1; i <= input.size(); i++) 
	{
		if(input[i] >= '0' && input[i] <= '9' && opt == '$')//�������֮ǰ 
		{
			head = head * 10 + int(input[i] - '0');
			continue;
		}
		if(input[i] >= '0' && input[i] <= '9' && opt != '$')//�������֮�� 
		{
			tail = tail * 10 + int(input[i] - '0');
			continue;
		}
		if(opt != '$' && (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') )
		{
			if(opt == '+') head += tail;
			if(opt == '-') head -= tail;
			if(opt == '*') head *= tail;
			if(opt == '/')
			{
				if(tail == 0)
				{
					cout << "ERROR";
					return 0;
				}
				else head /= tail;
			}
			opt = '$';
			continue;
		}
		if(opt == '$' && (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') )
		{	
			opt = input[i];
			continue;
		}
		if(input[i] == '=')
		{
			if(opt == '+') head += tail;
			if(opt == '-') head -= tail;
			if(opt == '*') head *= tail;
			if(opt == '/')
			{
				if(tail == 0)
				{
					cout << "ERROR";
					return 0;
				}
				else head /= tail;	 
			}
			cout << head;
			return 0;
		}
	}
	return 0;
}
