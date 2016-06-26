#include<iostream>
#include<stdio.h>
#pragma warning (disable :4996)
using namespace std;
class Fraction
{
public:
	Fraction(int up, int down)//���캯��
	{
		m_up = up;
		//���Լ�down������
		if (0==down)
		{
			cout << "��ĸ����Ϊ0,�ѽ���ĸ��Ϊ1";
			down = 1;
		}
		else
		{
			m_down = down;
		}
		gcd();//Լ��
	}
	void print()//�������
	{
		if (1 == m_down)//��ĸΪ1ֻ�������
		{
			cout << m_up;
		}
		else
		{
			cout << m_up << "/" << m_down;
		}
		cout << "\n";
	}
	int getUp()//�õ�����
	{
		return m_up;
	}
	int getDown()//�õ���ĸ
	{
		return m_down;
	}
	void gcd()//�������Լ����Լ��
	{
		int up = getUp();
		int down = getDown();
		int x;
		while (down)
		{
			x = up%down;
			up = down;
			down = x;
		}
		m_up /= up;
		m_down /= up;
		//����������
		if (m_up > 0 && m_down < 0 || m_up < 0 && m_down < 0)//ʹ�����ڷ�����
		{
			m_up = -m_up;
			m_down = -m_down;
		}
	}
	void cal(char c, Fraction b)
	{
		//cΪ�Ӽ��˳����ַ���
		//f����һ���μӼ���ķ��������������������������
		int up = b.getUp();
		int down = b.getDown();
		switch (c)
		{
		case'+':
			m_up = m_up*down + up*m_down;
			m_down = m_down*down;
			break;
		case'-':
			m_up = m_up*down - up*m_down;
			m_down = m_down*down; 
			break;
		case'*':
			m_up = m_up*up;
			m_down = m_down*down; 
			break;
		case'/':
			m_up = m_up*down;
			m_down = m_down*up; 
			break;
		}
		gcd();
	}
	void cal(char c, int intb)
	{
		Fraction b(intb,1);
		cal(c, b);
	}
	float toFloat()//������תΪС��
	{
		float f = (float)m_up / (float)m_down;
		return f;
	}
private:
	int m_up;//����
	int m_down;//��ĸ
};
void main()
{
	int up1, up2, down1, down2;
	char c;
	/*Fraction *p;
	p = new Fraction(1, 3);
	p->print();*/
	Fraction *p;
	while (scanf("%d/%d%c%d/%d",&up1,&down1,&c,&up2,&down2)==5)
	{
		Fraction a(up1,down1);
		Fraction b(up2,down2);
		a.cal(c, b);
		a.print();
		cout << a.toFloat() << "\n";
		//ÿ�μ��㣬a,b���ڴ��ַ����
		//p = &a;
		//cout << "a�ĵ�ַ" << (void*)p << endl;
		//p = &b;
		//cout << "b�ĵ�ַ" << (void*)p << endl;
	}
}

