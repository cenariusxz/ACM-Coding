#include<stdio.h>
int main()
{
    int n,m,a[51][6],i,j,count;
	double b[6],sum[51];
    while (scanf("%d%d",&n,&m)!=EOF)
	{
		for (i=0;i<n;i++) 
		{
			sum[i]=0;
			for (j=0;j<m;j++) 
			{
				scanf("%d",&a[i][j]);
				sum[i]+=a[i][j];
			}
		}
		for (i=0;i<n;i++)
		{
			printf("%.2lf",sum[i]/m);
			if (i==n-1) printf("\n");
			else printf(" ");
		}
		for (j=0;j<m;j++)
		{
			sum[j]=0;
			for (i=0;i<n;i++) sum[j]+=a[i][j];
			b[j]=sum[j]/n;
			printf("%.2lf",sum[j]/n);
			if (j==m-1) printf("\n");
			else printf(" ");
		}
		count=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (a[i][j]<b[j]) break;
			}
			if (j==m) count++;
		}
		printf("%d\n\n",count);
	}
    return 0;
}