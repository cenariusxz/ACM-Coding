#include<stdio.h>
int main()
{
	int gcd(int a,int b);
	int lcm(int a,int b);
	int m,n,t;
	printf("请输入两个正整数m,n.\n");
	scanf("%d%d",&m,&n);
	if (m>n)
	{
		t=m;
		m=n;
		n=t;
	}
	printf("最大公约数=%d\n",gcd(m,n));
	printf("最小公倍数=%d\n",lcm(m,n));
	return 0;
}

int gcd(int a,int b)
{
	int i;
	for (i=a;i>=1;i--)
	{
		if (a%i==0&&b%i==0) return i;
	}
}

int lcm(int a,int b)
{
	int i;
	for (i=b;i<=a*b;i++)
	{
		if (i%a==0&&i%b==0) return i;
	}
}