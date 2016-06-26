#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int i;
	struct node *next;
}Node;
void main()
{
	struct node *p = new struct node;
	cout << "struct node *p = new struct node;" << endl;
	cout << "sizeof(int):" << sizeof(int) << endl;//32位输出4 64位输出4
	cout << "sizeof(struct node):" << sizeof(struct node) << endl;//32位输出 8 64位输出16
	cout << "指针:" << sizeof(p) << endl;//32位输出4 64位输出8
	cout << "*p:" << sizeof(*p) << endl;//32位输出8 64位输出16
	//new和sizeof都有指针对齐问题

	cout << "堆地址问题：" << endl;
	cout << "*p:" << (void*)p << endl;//
	struct node *p1 = new struct node;
	cout << "*p1:" << (void*)p1 << endl;//
	struct node *p2 = new struct node;
	cout << "*p2:" << (void*)p2<< endl;//
	delete(p);
	delete(p1);
	delete(p2);
	//某次运行结果：
	//*p :0079FA85
	//*p1:0079F940
	//*p2:0079F6A0
	//运行结果说明堆地址的分配没有规律

	cout << "自由存储区地址问题：" << endl;
	p = (struct node*)malloc(sizeof(struct node));
	cout << "*p:" << (void*)p << endl;//
	p1 = (struct node*)malloc(sizeof(struct node));
	cout << "*p1:" << (void*)p1 << endl;//
	p2 = (struct node*)malloc(sizeof(struct node));
	cout << "*p2:" << (void*)p2 << endl;//
	free(p);
	free(p1);
	free(p2);
	//某次运行结果：
	//*p :0079F940
	//*p1:0079F828
	//*p2:0079FBE0
	//运行结果说明自由存储区地址的分配没有规律

	//从地址可以看出
	//两次分配，自由存储区和堆是一块地址，malloc分配的空间和new分配的空间都在堆中

	while (1);
}