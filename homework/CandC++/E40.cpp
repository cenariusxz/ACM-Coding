#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
void sort(int *,int);
void ins(int *,int,int);
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
	for (i=0;i<N;i++) printf("%d\t",a[i]);
	printf("\n");
	int m;
	printf("请输入要插入数组的数.\n");			//提示用户输入
	scanf("%d",&m);
	ins(p,n,m);
	printf("插入数后的结果：\n");
	for (i=0;i<N+1;i++) printf("%d\t",a[i]);
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

void ins(int *p,int n,int m)
{
	int *q,*s;
	for (q=p+N-1;q>=p+n;q--) *(q+1)=*q;			//将未被排序的数先向后移一位
	q=p+n-1;
	if (m>*q) *(q+1)=m;							//判断要插入的数是否为最大的数
	else										//将数插入数组中
	{
		for (;q>=p+1;q--)
		{
			*(q+1)=*q;
			if (m>*(q-1))
			{
				*q=m;
				break;
			}
		}
	}
}