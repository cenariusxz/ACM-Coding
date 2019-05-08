#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[11],i,j,t;
	printf("排序前：\n");
	srand(time(NULL));
	for (i=1;i<=10;i++)			//为十个数随机赋值
	{
		a[i]=rand();
		printf("%d\t",a[i]);
	}
	printf("\n排序后：\n");
	for (i=1;i<=10;i++)			//用选择法排序并输出
	{
		for (j=i+1;j<=10;j++)
		{
			if (a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		printf("%d\t",a[i]);	
	}
	return 0;
}