#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e3+5;
const int mod=1e9+7;

int n;
ll C[maxn];
int b[2][maxn];

struct num{
	int a,pos;
	bool operator < (const num x)const{
		if(a==x.a)return pos>x.pos;
		return a<x.a;
	}
}a[1005];

inline int lowbit(int x){
	return x&(-x);
}

void add(int x,int a){
	for(int i=x;i<=n;i+=lowbit(i)){
		C[i]+=a;
		if(C[i]>=mod)C[i]-=mod;
	}
}

int sum(int x){
	ll ans=0;
	for(int i=x;i>0;i-=lowbit(i)){
		ans+=C[i];
		if(ans>=mod)ans-=mod;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		memset(b,0,sizeof(b));
		int m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i].a);
			a[i].pos=i;
		}
		sort(a+1,a+n+1);

		for(int i=1;i<=n;++i){
			b[0][i]=1;
		}
		for(int i=2;i<=m;++i){
			memset(C,0,sizeof(C));
			int now=(i&1)?1:0;
			int nxt=now^1;
			for(int j=1;j<=n;++j){
				b[nxt][a[j].pos]=sum(a[j].pos-1);
				add(a[j].pos,b[now][a[j].pos]);
			}
		}

		int now=(m&1)?1:0;
		int nxt=now^1;
		ll ans=0;
		for(int i=1;i<=n;++i){
			ans+=b[nxt][i];
			if(ans>=mod)ans-=mod;
		}
		printf("Case #%d: %lld\n",q,ans);
	}
	return 0;
}
