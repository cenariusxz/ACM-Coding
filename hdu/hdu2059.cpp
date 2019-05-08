#include<stdio.h>
#include<string.h>
void fun(char x[],int l,int s)
{
	int i;
	for (i=s-1;i>=0;i--) x[i+l-s]=x[i];
	for (i=0;i<l-s;i++) x[i]='0';
}
int main()
{
	int T;
	while (scanf("%d",&T)!=EOF)
	{
		int i;
		for (i=1;i<=T;i++) 
		{
			char a[1002],b[1002],c[1002];
			int l1,l2,j,l;
			scanf("%s%s",a,b);
			printf("Case %d:\n",i);
			l1=strlen(a);
			l2=strlen(b);
			for (j=0;j<l1;j++) printf("%c",a[j]);
			printf(" + ");
			for (j=0;j<l2;j++) printf("%c",b[j]);
			printf(" = ");
			if (l1>l2) fun(b,l1,l2);
			if (l1<l2) fun(a,l2,l1);
			l=l1>=l2?l1:l2;
			for (j=0;j<l;j++) 
			{
				c[j]=a[j]+b[j]-'0';
			}
			for (j=l-1;j>0;j--) 
			{
				if (c[j]>'9') {c[j]-=10;c[j-1]+=1;}
			}
			if (c[0]>'9') {printf("1");c[0]-=10;}
			for (j=0;j<l;j++) printf("%c",c[j]);
			printf("\n");
			if (i!=T) printf("\n");
		}
	}
}