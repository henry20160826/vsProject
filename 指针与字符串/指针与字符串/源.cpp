#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)
void main()
{
	char pa[50] = { "ABCDEF" };//修改此处添加数字，使strcpy不溢出
	char *pb =  "EFG" ;//指针指向字符串常量，字符串常量不能被修改，但是指针的指向可以改变
	char *pc = { "EFG" };//指针指向字符串常量
	//pa[1] = 'A';//正确

	//pb[1] = 'A';//访问冲突 指针指向常量字符串，字符串不能被修改
	//*(pc + 1) = 'A';//指针指向常量字符串，字符串不能被修改

	//printf("*(pc+1):%c\n", *(pc + 1));//输出为F

	pb = pa;//
	//strcpy(pa, "ABCDEFGXYZ");//溢出
	pb = "D";//可以指向新的字符串,依然是常量字符串，不能修改,下面一句会报错
	//pb[1] = 'd';//这句会报错，原因见上一行
	printf("pa:%s\npb:%s\npc:%s\n",pa,pb,pc);
	while (1);
}