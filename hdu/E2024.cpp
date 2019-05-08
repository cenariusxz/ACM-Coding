#include<stdio.h>
int main()
{
	int A,B,i;
	while(scanf("%d%d",&A,&B)!=EOF)
	{
		if (A!=0||B!=0)
		{
			if (A>999) A-=(A/1000)*1000;
			int C=A;
			for (i=1;i<=B-1;i++)
			{
				C*=A;
				if (C>999) C-=(C/1000)*1000;
			}
			printf("%d\n",C);
		}
	}
	return 0;
}