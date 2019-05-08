#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=5e5;

int a[maxn];
int b[maxn];
ll c[maxn];
inline int lowbit(int x){return x&(-x);}
int n,cnt;
ll ls[maxn],rs[maxn],lb[maxn],rb[maxn];

void init(){
	memset(c,0,sizeof(c));
}

void add(int x){
	for(int i=x;i<=cnt;i+=lowbit(i)){
		c[i]++;
	}
}

ll get(int x){
	ll ans=0;
	for(int i=x;i>0;i-=lowbit(i)){
		ans+=c[i];
	}
	return ans;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		map<int,int> M;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		cnt=1;
		for(int i=2;i<=n;++i){
			if(b[i]!=b[i-1])b[++cnt]=b[i];
		}
		for(int i=1;i<=cnt;++i){
			M[b[i]]=i;
		}
		for(int i=1;i<=n;++i)a[i]=M[a[i]];
		memset(ls,0,sizeof(ls));
		memset(rs,0,sizeof(rs));
		memset(lb,0,sizeof(lb));
		memset(rb,0,sizeof(rb));
		ll sum1=0,sum2=0;
		init();
		for(int i=1;i<=n;++i){
			ls[i]=get(a[i]-1);
			lb[i]=get(cnt)-get(a[i]);
			sum1+=ls[i];
			sum2+=lb[i];
			add(a[i]);
		}
		init();
		for(int i=n;i>=1;--i){
			rs[i]=get(a[i]-1);
			rb[i]=get(cnt)-get(a[i]);
			add(a[i]);
		}
		ll ans=0;
		ans+=sum1*sum2;
		for(int i=1;i<=n;++i){
			ans-=ls[i]*rs[i]+lb[i]*rb[i]+ls[i]*lb[i]+rs[i]*rb[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
