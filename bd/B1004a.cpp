#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long shi[15],ans[10005];
int main()
{
	int T,t,b,m,n,cnt,i;
	double x;
	long long tmp,fx;
	scanf("%d",&T);
	shi[0]=1;
	for (i=1;i<=11;i++)
		shi[i]=shi[i-1]*10;
	for (t=1;t<=T;t++)
	{
		scanf("%lf",&x);
		fx=(long long)(x*shi[6]);
		cnt=0;
		for (b=2;b<=10;b++)
			for (m=1;m<=9;m++)
				for (n=0;n<=9;n++)
				{
					tmp=m*shi[b-1]*fx+n*fx-n*shi[b-1]*shi[6]-m*shi[6];
					if (tmp%(shi[7]-10*fx)!=0) continue;
					tmp=tmp/(shi[7]-10*fx);
					if (tmp<0||tmp>=shi[b-2]) continue;
					ans[++cnt]=m*shi[b-1]+tmp*10+n;
				}
		printf("Case #%d:\n%d\n",t,cnt);
		if (cnt!=0) sort(ans+1,ans+cnt+1);
		for (i=1;i<cnt;i++) printf("%lld ",ans[i]);
		if (cnt!=0) printf("%lld\n",ans[cnt]);
	}
	return 0;
}
