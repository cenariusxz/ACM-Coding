#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

typedef long long ll;
const int maxn=1005;
const int mod=1e4+7;
const int INF=0x3f3f3f3f;

struct box{
	int w,num;
}b[maxn];

ll A[maxn+5],AA[maxn+5];
int n,w,num[maxn],cnt;
int sum[maxn];

ll QP(ll a,int n){
	ll ans=1,tmp=a;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

void init(){
	A[0]=1;
	for(int i=1;i<=maxn;++i)A[i]=A[i-1]*i%mod;
	AA[maxn]=QP(A[maxn],mod-2);
	for(int i=maxn;i>=1;--i)AA[i-1]=AA[i]*i%mod;
}

ll dfs(int s,int ww,ll AAA,int MIN,int nn){
	ll ans=0;
	if(s==0){
//		printf("%d %d %d\n",w,ww,MIN);
		if(b[MIN].w<=w-ww)return 0;
		else {
//			printf("aaa\n");
			return A[nn]*AAA%mod;

		}
	}
	for(int i=0;i<=b[s].num;++i){
		int ww2=ww+i*b[s].w;
		ll AAA2=AAA*AA[i];
		int MIN2;
		if(i!=b[s].num)MIN2=s;
		else MIN2=MIN;
		int nn2=nn+i;
		if(ww2>w)break;
		else if(sum[s-1]+ww2+b[MIN2].w<=w)continue;
		else ans+=dfs(s-1,ww2,AAA2,MIN2,nn2);
		if(ans>=mod)ans-=mod;
	}
	return ans;
}

int main(){
	int T;
	init();
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d%d",&n,&w);
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;++i){
			int a;
			scanf("%d",&a);
			num[a]++;
		}
		cnt=0;
		for(int i=1;i<=w;++i){
			if(num[i]){
				++cnt;
				b[cnt].w=i;
				b[cnt].num=num[i];
			}
		}
		for(int i=1;i<=w;++i)sum[i]=sum[i-1]+b[i].w*b[i].num;
		b[cnt+1].w=INF;
		ll ans=dfs(cnt,0,1,cnt+1,0);
		printf("Case %d: %lld\n",q,ans);
	}
	return 0;
}
