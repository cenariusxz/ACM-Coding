#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

ll dp[100005];
int val[105],t[105];

void check(int n,int T){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i){
		for(int j=T;j>=t[i];--j){
			dp[j]=max(dp[j],dp[j-t[i]]+val[i]);
		}
	}
}

int main(){
	int n,T;
	while(scanf("%d%d",&n,&T)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d%d",&t[i],&val[i]);
		int bit=0;
		int tmp=T;
		while(tmp){
			bit++;
			tmp/=10;
		}
		tmp=T;
		if(bit>=5){
			int num=1;
			for(int i=1;i<=bit-5;++i)num*=10;
			tmp=ceil(tmp*1.0/num);
			for(int i=1;i<=n;++i){
//				t[i]=(t[i]+num-1)/num;
				t[i]=ceil(t[i]*1.0/num);
			}
		}
//		printf("%d\n",tmp);
		check(n,tmp);
		ll ans=0;
		for(int i=0;i<=tmp;++i)ans=max(ans,dp[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
