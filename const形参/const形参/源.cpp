#include<iostream>
using namespace std;
void t(const int i)//����const �����ں����в��ᱻ�޸�
{
	//i = 0;//���� �����ǿ��޸ĵ���ֵ
	cout << i << endl;
}
void t1(const int *pi)
{
	//*pi = 4;//���� �����ǿ��޸ĵ���ֵ
	cout << *pi << endl;

}
void t2(int pi)
{
	cout << pi << endl;

}
void c(const char *p)
{
	//*p = 'c';//���� �����ǿ��޸ĵ���ֵ
}
void main()
{
	int i = 0;
	t(i);
	int *pi = &i;
	t1(pi);//��const�͵�ʵ�ο��Դ���cost�͵��β�
	const int n = 0;
	t2(n);//��ֵͨ����const��ʵ�ο��Դ���const�͵��β�
	const int *pn = 0;
	//t2(pn);//��ַ��ı�������const�Ͳ��ܴ���const��

	//�Ա�����Լ���ڳ�������ʱ���Լ�ǿ�����ǲ��ܼ�������Ҫ����ԭ���ǳ���ָ�룬���Ǵ��뺯�����Ϊһ��ָ�룬ֵ���޸�

	while (true)
	{

	}
}