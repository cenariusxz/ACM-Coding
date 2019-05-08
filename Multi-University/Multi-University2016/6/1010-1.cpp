#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

ll ans=0;

void check(ll p,ll q,ll step,int wait){
//	printf("aaa %lld %lld %lld %d\n",p,q,step,wait);
	if(p<0)p=0;
	ll a=p-q;
	if(a>0)return;
	ll need=-a;
	if(need>=wait)need-=wait;
	else need=0;
	if(step+need<ans)ans=step+need;
}

void dfs(ll P,ll q,ll step,int wait){
//	printf("bbb %lld %lld %lld %d\n",P,q,step,wait);
	if(P==q){
		check(P,q,step,wait);
		return;
	}
	ll a=P-q;
	ll tmp=a;
	int p=0;
	while(tmp){
		tmp/=2;
		p++;
	}
	if(a==((1ll<<p)-1)){
//	printf("ccc %lld %d\n",a,p);
		ll t=step;
		int wt=wait;
		if(t!=0){t++;wt++;}
		check(P-((1ll<<p)-1),q,t+p,wt);
		return;
	}

	ll sub=(1ll<<p)-1;	//p ci
	ll t=step;
	int wt=wait;
	if(t!=0){t++;wt++;}
	check(P-sub,q,t+p,wt);

	dfs(P-((1ll<<(p-1))-1),q,step+p-1+(step==0?0:1),wait+(step==0?0:1));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int p,q;
		scanf("%d%d",&p,&q);
		if(p<=q)printf("%d\n",q-p);
		else{
			ans=1ll<<50;
			dfs(p,q,0,0);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
