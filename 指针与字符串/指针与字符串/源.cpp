#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)
void main()
{
	char pa[50] = { "ABCDEF" };//�޸Ĵ˴�������֣�ʹstrcpy�����
	char *pb =  "EFG" ;//ָ��ָ���ַ����������ַ����������ܱ��޸ģ�����ָ���ָ����Ըı�
	char *pc = { "EFG" };//ָ��ָ���ַ�������
	//pa[1] = 'A';//��ȷ

	//pb[1] = 'A';//���ʳ�ͻ ָ��ָ�����ַ������ַ������ܱ��޸�
	//*(pc + 1) = 'A';//ָ��ָ�����ַ������ַ������ܱ��޸�

	//printf("*(pc+1):%c\n", *(pc + 1));//���ΪF

	pb = pa;//
	//strcpy(pa, "ABCDEFGXYZ");//���
	pb = "D";//����ָ���µ��ַ���,��Ȼ�ǳ����ַ����������޸�,����һ��ᱨ��
	//pb[1] = 'd';//���ᱨ��ԭ�����һ��
	printf("pa:%s\npb:%s\npc:%s\n",pa,pb,pc);
	while (1);
}