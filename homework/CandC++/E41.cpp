#include<stdio.h>
#include<string.h>
void calcu(char *);
int main()
{
	char a[6],*p;
	printf("请输入由数字构成的一个字符串(长度小于5).\n");			//提示用户输入
	scanf("%s",a);
	p=a;
	calcu(p);
	return 0;
}

void calcu(char *p)
{
	int max=0,min=0,i,j,t,len;
	int b[6];
	len=strlen(p);
	for (i=0;i<len;i++) b[i]=*(p+i)-48;								//将数组a复制到数组b
	for (i=0;i<len;i++) for (j=i+1;j<len;j++) if (b[j]<b[i])		//对数组b进行排序
	{
		t=b[j];
		b[j]=b[i];
		b[i]=t;
	}
	for (i=len-1;i>=0;i--)											//计算组成的最大值
	{
		t=b[i];
		for (j=1;j<=i;j++) t*=10;
		max+=t;
	}
	printf("最大值：%d\n",max);
	if (b[0]==0) for (i=0;i<len;i++) if (b[i]!=0)					//排除0在开头的情况，计算组成的最小值
	{
		t=b[0];
		b[0]=b[i];
		b[i]=t;
		break;
	}
	for (i=0;i<len;i++)
	{
		t=b[i];
		for (j=1;j<=len-i-1;j++) t*=10;
		min+=t;
	}
	printf("最小值：%d\n",min);
}