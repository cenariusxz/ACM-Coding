#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a ;
	srand(time(NULL));
	a=1+rand()%3;
	printf("%d\n",a);
	return 0;
}