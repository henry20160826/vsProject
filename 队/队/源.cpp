#include<iostream>
#define N 100
using namespace std;
class Queue
{
public:
	Queue()
	{
		Queue(N);
	}
	Queue(int n)
	{
		len = n;
		num = new int[n];
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
	bool enQueue(int n)
	{
		if (isFull())
		{
			return false;
		}
		num[rear] = n;
		rear = (rear + 1) % len;
		return true;
	}
	bool deQueue(int &n)
	{
		if (isEmpty())
		{
			return false;
		}
		n = num[head];
		head = (head + 1) % len;
		return true;
	}
private:
	int *num;
	int head, rear;
	int len;
};
void main()
{

}