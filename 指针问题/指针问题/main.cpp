#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
void swap1(char *pa, char *pb)
{
	/*����ʵ�ֵ���
		pa��pb�еĵ�ַ���ָı�
		��Ϊ���Ӻ����д���Ĳ����ǿ�����������������ʵ��pa��pb�������������������û��Ӱ��
	*/
	char *temp = pa;
	pa = pb;
	pb = temp;
	printf("swap1�е�pa��%d,pb:%d\n", pa, pb);
	printf("swap1�е�&pa��%d,&pb:%d\n", &pa, &pb);
}
void swap2(char *pa, char *pb)
{
	/*����ʵ�ֵ���
		pa��pb�Կ��������ƴ��뺯��������pa��pb�е�����������һ����Ҳ���Ǳ�������ʵ��a��b�ĵ�ַ
		Ȼ�󽻻�a��b�е�����
		���뽻�����ݵĵ�ַ���룬��*ȡ�����е����ݽ��н���
	*/
	char temp = *pa;
	*pa = *pb;
	*pb = temp;
	printf("swap2�е�pa��%d,pb:%d\n", pa, pb);
	printf("swap2�е�&pa��%d,&pb:%d\n", &pa, &pb);

}
void swap(char **x, char**y) {
	char *p;
	p = *x;
	*x = *y;
	*y = p;
}
//void swap3(char *pa,char *pb)
//{
//	�����ַ���
//	������֪��ʲôԭ��
//	char temp[100];
//	strcpy(temp, pa);
//	strcpy(pa, pb);
//	strcpy(pb,temp);
//}
void main()
{
	// * ȡ����
	// & ȡ��ַ
	char *pa, *pb, a, b;
	//ָ����Ҫ��ʼ������Ҫ��һ����ͬ���͵ı���������malloc����һ���µ��ڴ�ռ�
	//���û�г�ʼ��ָ�룬ָ��û�еõ��ڴ�ռ䣬�����������*ȡ���е����ݻᱨ��
	//pa��һ����ַ
	//&a��һ����ַ
	//*pa,a�������ַ�е�����

	//�ַ�����
	pa = &a;
	pb = &b;
	*pa = 'a';
	*pb = 'b';
	printf("pa:%d,&a:%d\n", pa, &a);//������������ڴ��еĵ�ַ���
	printf("pb:%d,&b:%d\n", pb, &b);
	printf("&pa:%d,&pb:%d\n", &pa, &pb);
	cout << "***********************\n";
	cout << *pa << "\n";//���ַ����
	cout << pa << "\n";//���ַ������
	cout << "***********************\n";
	swap1(pa, pb);
	printf("swap1:\na:%c,b:%c\n", *pa, *pb);
	printf("a:%c,b:%c\n", a, b);

	*pa = 'a';
	*pb = 'b';
	swap2(pa, pb);
	printf("swap2:\na:%c,b:%c\n", *pa, *pb);
	printf("a:%c,b:%c\n", a, b);

	//�ַ�������
	char *sa = { "china" };
	char *sb = { "us" };
	pa = sa;
	pb = sb;
	char **ppa = &sa;
	char **ppb = &sb;
	//swap1(sa,sb);//�ڴ˴���������
	//swap2(pa, pb);//��֪����ô�ᱨ��
	swap(ppa, ppb);//�ɹ�������ʹ�ö���ָ��
	printf("china:%s,us:%s", sa, sb);
	cout << "\n" << sa;//���ַ������
	cout << "\n" << *sa;//����ַ����ĵ�һ����ĸ
	while (true);
}
