#include<stdio.h>
int main()
{
	int a,b,x1,x2,t,i;
	printf("请输入两个正整数a b.\n");				//提示用户输入
	scanf("%d%d",&a,&b);
	if (a>b)										//首先将a,b按大小顺序排列
	{
		t=a;
		a=b;
		b=t;
	}
	for (i=a;i>=1;i--)								//从小数到1求判断最大公因数
	{
		if (!(a%i)&&!(b%i)) 
		{
			x1=i;
			break;
		}
	}
	for (i=b;i<=a*b;i++)							//从大数到两数乘积求最小公倍数
	{
		if (!(i%a)&&!(i%b)) 
		{
			x2=i;
			break;
		}
	}
	printf("最大公因数=%d\n最小公倍数=%d\n",x1,x2);	//输出
	return 0;
}