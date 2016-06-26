#include <sys/types.h>
#include <unistd.h>
#include<iostream>
void main()
{
	for (int i = 0; i < 2; i++)
	{
		fork();

	}
}