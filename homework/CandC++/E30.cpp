#include<stdio.h>
int main()
{
	int gcd(int a,int b);
	int lcm(int a,int b);
	int m,n,t;
	printf("����������������m,n.\n");
	scanf("%d%d",&m,&n);
	if (m>n)
	{
		t=m;
		m=n;
		n=t;
	}
	printf("���Լ��=%d\n",gcd(m,n));
	printf("��С������=%d\n",lcm(m,n));
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