#include<stdio.h>
#include<math.h>
int main()
{
	long long N,M;
	while (scanf("%I64d%I64d",&N,&M)!=EOF)
	{
		if (N!=0||M!=0)
		{
			long long i;
			double d,x2;
			for (i=1;i<=N;i++)
			{
				d=1-4*i+4*i*i+8*M;
				x2=(sqrt(d)-1)/2;
				if (x2>=i&&x2==(long long)x2&&x2<=N) printf("[%I64d,%I64d]\n",i,(long long)x2);
			}
		}
	}
	return 0;
}