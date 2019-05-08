#include<stdio.h>
int main()
{
	int a,n,S=0,t=0,i,m;
	printf("请输入两个正整数a n.\n");
	scanf("%d%d",&a,&n);
	m=a;
	for (i=1;i<=n;i++,m=m*10)
	{
		t=t+m;
		S=S+t;
	}
	printf("S=%d\n",S);
	return 0;
}