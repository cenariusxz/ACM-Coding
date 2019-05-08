#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double dp[100005];
int a[105];
double p[105];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		double P;
		int n;
		scanf("%lf%d",&P,&n);
		for(int i=1;i<=n;++i)scanf("%d%lf",&a[i],&p[i]);
		for(int i=0;i<=n*100;++i)dp[i]=1000;
		dp[0]=0;
		int lim=0;
		for(int i=1;i<=n;++i){
			for(int j=lim+a[i];j>=a[i];--j){
				double tmp=dp[j-a[i]]+(1-dp[j-a[i]])*p[i];
				if(tmp<P&&tmp<dp[j]){
					dp[j]=tmp;
					if(j>lim)lim=j;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=lim;++i){
			if(dp[i]<P)ans=i;
		}
		printf("Case %d: %d\n",q,ans);

	}
	return 0;
}
