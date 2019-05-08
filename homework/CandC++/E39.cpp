#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
void sort(int *,int);
int main()
{
	int a[N+1],n,i,*p;
	srand(time(NULL));
	for (i=0;i<N;i++)							//用随机数初始化数组
	{
		a[i]=rand();
		printf("%d\t",a[i]);
	}
	printf("请输入要排序的元素个数.\n");		//提示用户输入
	scanf("%d",&n);
	p=a;
	sort(p,n);
	printf("对前%d个数排序后：\n",n);
	for (i=0;i<10;i++) printf("%d\t",a[i]);
	printf("\n");
	return 0;
}

void sort(int *p,int n)
{
	int *q,*s,t;
	for (q=p;q<(p+n);q++)						//排序
	{
		for (s=q+1;s<(p+n);s++)
		{
			if (*s<*q)
			{
				t=*s;
				*s=*q;
				*q=t;
			}
		}
	}
}