#include<iostream>
using namespace std;
bool check(char *p)
{
	int len = strlen(p);
	int i = 0,j = len - 1;
	while(i<j)
	{
		if (p[i] != p[j])
		{
			break;
		}
		i++;
		j--;
	}
	if (i < j)
	{
		return false;
	}
	return true;
}
void main()
{
	char s[] = "abcgcbfa";
	cout << check(s) << endl;
	while (true)
	{

	}
}