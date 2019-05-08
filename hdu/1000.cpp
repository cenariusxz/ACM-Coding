#include<stdio.h>
int main()
{
    int m,n,sum=0,ave,i,count=1,ave;
    while (scanf("%d%d",&n,&m)!=EOF)
	{
		for (i=1;i<=n;i++,count++)
		{
			sum+=2*i;
			if (count==m||i==n)
			{
				ave=(double)sum/count;
				printf("%d",ave);
				if (i!=n) printf(" ");
				count=1;
				sum=0;
			}
		}
		printf("\n");
	}
    return 0;
}