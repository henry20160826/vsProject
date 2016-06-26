#include<iostream>
#define N 100
using namespace std;
template <class T>class Queue
{
public:
	Queue(const int n = N)//形参默认值
	{
		len = n;
		t = new T[n];
		head = 0;
		rear = 0;
	}
	int getLength()
	{
		return (rear + len - head) % len;
	}
	bool isEmpty()
	{
		return head == rear;
	}
	bool isFull()
	{
		return (rear + 1) % len == head;
	}
	bool enQueue(T n)
	{
		if (isFull())
		{
			return false;
		}
		t[rear] = n;
		rear = (rear + 1) % len;
		return true;
	}
	bool deQueue(T &n)
	{
		if (isEmpty())
		{
			return false;
		}
		n = t[head];
		head = (head + 1) % len;
		return true;
	}
private:
	int *t;
	int head, rear;
	int len;
};
void main()
{
	Queue<int> *d = new Queue<int>();
	d->enQueue(2);
	int i;
	d->deQueue(i);
	cout << i << endl;
	cout << d->getLength() << endl;
	while (1);
}