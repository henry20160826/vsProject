#include<iostream>
using namespace std;
#define N 50
//-1( )1
//-2[ ]2
//-3{ }3
class Stack
{
private:
	char num[N];
	int top = 0;
public:
	int getNum()
	{
		return top;
	}
	bool isEmpty()
	{
		return top == 0 ? true : false;
	}
	bool isFull()
	{
		return top == N ? true : false;
	}
	bool pop(char &x)
	{
		if (!isEmpty())
		{
			x = num[--top];
			return true;
		}
		return false;
	}
	bool push(char x)
	{
		if (!isFull())
		{
			num[top] = x;
			top++;
			return true;
		}
		return false;
	}
	bool check(char x)
	{
		char m;
		if (pop(m))
		{
			if (x - m == 1 || x - m == 2)
			{
				return true;
			}
			else {
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};
void main()
{
	char a[1000];
	cin >> a;
	bool flag = true;
	Stack stack;
	for (int i = 0; a[i] != '\0'; i++)
	{
		switch (a[i])
		{
		case'(':
		case'[':
		case'{':
			if (!stack.push(a[i]))
			{
				cout << "Õ»Òç³ö\n";
				flag = false;
			}
			break;
		case')':
		case']':
		case'}':
			if (!stack.check(a[i]))
			{
				flag = false;
			}
			break;
		}
		if (!flag)
		{
			break;
		}
	}
	if (stack.isEmpty() && flag)
	{
		cout << "Æ¥Åä\n";
	}
	else
	{
		cout << "²»Æ¥Åä";
	}
	while (1);
}