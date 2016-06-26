#include<iostream>
#include<stdio.h>
#pragma warning (disable :4996)
using namespace std;
class Fraction
{
public:
	Fraction(int up, int down)//构造函数
	{
		m_up = up;
		//可以加down非零检测
		if (0==down)
		{
			cout << "分母不能为0,已将分母设为1";
			down = 1;
		}
		else
		{
			m_down = down;
		}
		gcd();//约分
	}
	void print()//输出分数
	{
		if (1 == m_down)//分母为1只输出分子
		{
			cout << m_up;
		}
		else
		{
			cout << m_up << "/" << m_down;
		}
		cout << "\n";
	}
	int getUp()//得到分子
	{
		return m_up;
	}
	int getDown()//得到分母
	{
		return m_down;
	}
	void gcd()//计算最大公约数，约分
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
		//处理负号问题
		if (m_up > 0 && m_down < 0 || m_up < 0 && m_down < 0)//使负号在分子上
		{
			m_up = -m_up;
			m_down = -m_down;
		}
	}
	void cal(char c, Fraction b)
	{
		//c为加减乘除四种符号
		//f是另一个参加计算的分数，计算结果赋给现在这个分数
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
	float toFloat()//将分数转为小数
	{
		float f = (float)m_up / (float)m_down;
		return f;
	}
private:
	int m_up;//分子
	int m_down;//分母
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
		//每次计算，a,b的内存地址不变
		//p = &a;
		//cout << "a的地址" << (void*)p << endl;
		//p = &b;
		//cout << "b的地址" << (void*)p << endl;
	}
}

