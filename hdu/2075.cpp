#include<stdio.h>
struct Data
{
	int a;
	int b;
}data[9];
int main()
{
	int T;
	while (scanf("%d",&T)!=EOF)
	{
		int i;
		for (i=1;i<=T;i++)
		{
			int n,k;
			scanf("%d%d",&n,&k);
			int j,t,l;
			for (j=1;j<=k;j++) scanf("%d%d",&data[j].a,&data[j].b);
			for (j=1;j<=k;j++)
			{
				for (l=j+1;l<=k;l++)
				{
					if (data[j].a<data[l].a)
					{
						t=data[j].a;
						data[j].a=data[l].a;
						data[l].a=t;
						t=data[j].b;
						data[j].b=data[l].b;
						data[l].b=t;
					}
				}
			}
		}
	}
	return 0;
}