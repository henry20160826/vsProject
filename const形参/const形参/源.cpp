#include<iostream>
using namespace std;
void t(const int i)//加上const 变量在函数中不会被修改
{
	//i = 0;//报错 必须是可修改的左值
	cout << i << endl;
}
void t1(const int *pi)
{
	//*pi = 4;//报错 必须是可修改的左值
	cout << *pi << endl;

}
void t2(int pi)
{
	cout << pi << endl;

}
void c(const char *p)
{
	//*p = 'c';//报错 必须是可修改的左值
}
void main()
{
	int i = 0;
	t(i);
	int *pi = &i;
	t1(pi);//非const型的实参可以传给cost型的形参
	const int n = 0;
	t2(n);//普通值，非const型实参可以传给const型的形参
	const int *pn = 0;
	//t2(pn);//地址类的变量，非const型不能传给const型

	//对变量的约束在程序运行时可以加强，但是不能减弱，更要避免原本是常量指针，但是传入函数后变为一般指针，值被修改

	while (true)
	{

	}
}