#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=105;

int a[maxn];
double dp[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[1]=1;
		for(int i=1;i<n;++i){
			int tmp=6;
			if(i+tmp>n)tmp=n-i;
			for(int j=1;j<=tmp;++j){
				dp[i+j]+=dp[i]/tmp;
			}
		}
		double ans=0;
		for(int i=1;i<=n;++i){
			ans+=dp[i]*a[i];
		}
		printf("Case %d: %.10lf\n",q,ans);
	}
	return 0;
}
