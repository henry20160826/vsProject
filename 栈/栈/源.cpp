#include<iostream>
#define N 100
using namespace std;
class Stack
{
public:
	Stack()
	{
		Stack(N);
	}
	Stack(int n)
	{
		top = 0;
		num = new int[n];
	}
	~Stack()
	{
		delete(num);
	}
	int getCount()
	{
		return top;
	}
	bool isEmpty()
	{
		return top == 0 ? true : false;
	}
	bool isFull()
	{
		return top == len ? true : false;
	}
	bool pop(int &n)
	{
		if (isEmpty())
		{
			return false;
		}
		n = num[--top];
		return true;
	}
	bool push(int n)
	{
		if (isFull())
		{
			return false;
		}
		num[top++] = n;
		return true;
	}
private:
	int *num;
	int top, len;
};
void main()
{

}