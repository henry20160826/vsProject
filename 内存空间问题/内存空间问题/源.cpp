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
	cout << "sizeof(int):" << sizeof(int) << endl;//32λ���4 64λ���4
	cout << "sizeof(struct node):" << sizeof(struct node) << endl;//32λ��� 8 64λ���16
	cout << "ָ��:" << sizeof(p) << endl;//32λ���4 64λ���8
	cout << "*p:" << sizeof(*p) << endl;//32λ���8 64λ���16
	//new��sizeof����ָ���������

	cout << "�ѵ�ַ���⣺" << endl;
	cout << "*p:" << (void*)p << endl;//
	struct node *p1 = new struct node;
	cout << "*p1:" << (void*)p1 << endl;//
	struct node *p2 = new struct node;
	cout << "*p2:" << (void*)p2<< endl;//
	delete(p);
	delete(p1);
	delete(p2);
	//ĳ�����н����
	//*p :0079FA85
	//*p1:0079F940
	//*p2:0079F6A0
	//���н��˵���ѵ�ַ�ķ���û�й���

	cout << "���ɴ洢����ַ���⣺" << endl;
	p = (struct node*)malloc(sizeof(struct node));
	cout << "*p:" << (void*)p << endl;//
	p1 = (struct node*)malloc(sizeof(struct node));
	cout << "*p1:" << (void*)p1 << endl;//
	p2 = (struct node*)malloc(sizeof(struct node));
	cout << "*p2:" << (void*)p2 << endl;//
	free(p);
	free(p1);
	free(p2);
	//ĳ�����н����
	//*p :0079F940
	//*p1:0079F828
	//*p2:0079FBE0
	//���н��˵�����ɴ洢����ַ�ķ���û�й���

	//�ӵ�ַ���Կ���
	//���η��䣬���ɴ洢���Ͷ���һ���ַ��malloc����Ŀռ��new����Ŀռ䶼�ڶ���

	while (1);
}