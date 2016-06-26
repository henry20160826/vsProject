#include<iostream>
#define N 100
using namespace std;
template <class T>class Stack
{
public:
	Stack(const int n = N)//形参默认值
	{
		len = n;
		top = 0;
		t = new T[n];
	}
	~Stack()
	{
		delete(t);
	}
	int getCount()
	{
		return top;
	}
	bool isEmpty()
	{
		return top == 0;
	}
	bool isFull()
	{
		return top == len;
	}
	bool pop(T &n)
	{
		if (isEmpty())
		{
			return false;
		}
		n = t[--top];
		return true;
	}
	bool push(T n)
	{
		if (isFull())
		{
			return false;
		}
		t[top++] = n;
		return true;
	}
private:
	T *t;
	int top, len;
};
void main()
{
	Stack<int> *s = new Stack<int>();
	cout << s->push(0) << endl;
	cout << s->getCount() << endl;
	int i;
	s->pop(i);
	cout << i << endl;
	delete(s);
	while (1);
}