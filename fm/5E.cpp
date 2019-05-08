#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e7;

int good[maxn+5],pnum[maxn+5];
ll gn[maxn+5];
int num;

void init(){
	num=0;
	memset(good,0,sizeof(good));
	memset(pnum,0,sizeof(pnum));
	for(int i=2;i<=maxn;++i){
		if(!pnum[i]){
			pnum[i]=1;
			for(ll j=2;i*j<=maxn;++j){
				if(!(j%i))good[i*j]=1;
				else pnum[i*j]++;
			}
		}
	}
	for(int i=2;i<=maxn;++i)if(!good[i])gn[++num]=i;
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		ll n;
		scanf("%lld",&n);
		ll ans=0;
		for(int i=1;i<=num&&gn[i]*gn[i]<=n;++i){
			if(pnum[gn[i]]%2)ans+=n/(gn[i]*gn[i]);
			else ans-=n/(gn[i]*gn[i]);
		}
		printf("%lld\n",n-ans);
	}
	return 0;
}
