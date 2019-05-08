#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=50005;
const int mod=1e9+9;

ll dp[maxn][205];
ll sum[maxn][205];
int n,m,d;
int a[maxn],b[maxn];
int sta[maxn],len[maxn];

void init(){
	int posl=1,posr=1;
	for(int i=1;i<=n;++i){
		while(posl<=m&&b[posl]+d<=a[i])posl++;
		while(posr<m&&b[posr]<a[i]+d)posr++;
		if(b[posr]>=a[i]+d)posr--;
		sta[i]=posl-1;
		len[i]=posr-posl+2;
	}
//	for(int i=1;i<=n;++i)printf("%d %d\n",sta[i],len[i]);
}

ll solve(){
	ll ss=0,stmp=0;
	for(int i=1;i<=len[1];++i){
		dp[1][i]=1;
		sum[1][i]=sum[1][i-1]+dp[1][i];
		if(sum[1][i]>=mod)sum[1][i]-=mod;
		stmp+=dp[1][i];
		if(stmp>=mod)stmp-=mod;
	}
	for(int i=2;i<=n;++i){
		ss=stmp;stmp=0;
		for(int j=1;j<=len[i];++j){
			int k=sta[i]+j-sta[i-1];
			if(k>len[i-1])k=len[i-1];
			dp[i][j]=sum[i-1][k];
			sum[i][j]=sum[i][j-1]+dp[i][j];
			if(sum[i][j]>=mod)sum[i][j]-=mod;
			stmp+=dp[i][j];
			if(stmp>=mod)stmp-=mod;
		}
/*		if(i==2){
			printf("aaa:%lld %lld\n",dp[i][1],sum[1]);
		}*/
	}
//	printf("%lld %lld\n",dp[2][1],dp[3][1]);
	return stmp;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d%d%d",&n,&m,&d);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&b[i]);
		init();
		ll ans=solve();
		printf("Case #%d: %lld\n",q,ans);
	}
	return 0;
}
