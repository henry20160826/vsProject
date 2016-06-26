#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
void swap1(char *pa, char *pb)
{
	/*以下实现的是
		pa与pb中的地址数字改变
		因为在子函数中传入的参数是拷贝，并不是外面真实的pa，pb，所以这个交换对外面没有影响
	*/
	char *temp = pa;
	pa = pb;
	pb = temp;
	printf("swap1中的pa：%d,pb:%d\n", pa, pb);
	printf("swap1中的&pa：%d,&pb:%d\n", &pa, &pb);
}
void swap2(char *pa, char *pb)
{
	/*以下实现的是
		pa和pb以拷贝的形势传入函数，但是pa，pb中的内容与外面一样，也就是保存了真实的a，b的地址
		然后交换a，b中的内容
		将想交换内容的地址传入，用*取出其中的内容进行交换
	*/
	char temp = *pa;
	*pa = *pb;
	*pb = temp;
	printf("swap2中的pa：%d,pb:%d\n", pa, pb);
	printf("swap2中的&pa：%d,&pb:%d\n", &pa, &pb);

}
void swap(char **x, char**y) {
	char *p;
	p = *x;
	*x = *y;
	*y = p;
}
//void swap3(char *pa,char *pb)
//{
//	交换字符串
//	报错，不知道什么原因
//	char temp[100];
//	strcpy(temp, pa);
//	strcpy(pa, pb);
//	strcpy(pb,temp);
//}
void main()
{
	// * 取对象
	// & 取地址
	char *pa, *pb, a, b;
	//指针需要初始化，需要绑定一个相同类型的变量，或者malloc分配一块新的内存空间
	//如果没有初始化指针，指针没有得到内存空间，这种情况下用*取其中的内容会报错
	//pa是一个地址
	//&a是一个地址
	//*pa,a是这个地址中的内容

	//字符交换
	pa = &a;
	pb = &b;
	*pa = 'a';
	*pb = 'b';
	printf("pa:%d,&a:%d\n", pa, &a);//输出的数字是内存中的地址编号
	printf("pb:%d,&b:%d\n", pb, &b);
	printf("&pa:%d,&pb:%d\n", &pa, &pb);
	cout << "***********************\n";
	cout << *pa << "\n";//按字符输出
	cout << pa << "\n";//按字符串输出
	cout << "***********************\n";
	swap1(pa, pb);
	printf("swap1:\na:%c,b:%c\n", *pa, *pb);
	printf("a:%c,b:%c\n", a, b);

	*pa = 'a';
	*pb = 'b';
	swap2(pa, pb);
	printf("swap2:\na:%c,b:%c\n", *pa, *pb);
	printf("a:%c,b:%c\n", a, b);

	//字符串交换
	char *sa = { "china" };
	char *sb = { "us" };
	pa = sa;
	pb = sb;
	char **ppa = &sa;
	char **ppb = &sb;
	//swap1(sa,sb);//在此处不起作用
	//swap2(pa, pb);//不知道怎么会报错
	swap(ppa, ppb);//成功交换，使用多重指针
	printf("china:%s,us:%s", sa, sb);
	cout << "\n" << sa;//按字符串输出
	cout << "\n" << *sa;//输出字符串的第一个字母
	while (true);
}
