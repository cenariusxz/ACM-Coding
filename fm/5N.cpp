#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int pnum[maxn],good[maxn];

void init(){
	memset(pnum,0,sizeof(pnum));
	memset(good,0,sizeof(good));
	for(int i=2;i<=100000;++i){
		if(!pnum[i]){
			pnum[i]=1;
			for(int j=2;i*j<=100000;++j){
				if(!(j%i))good[i*j]=1;
				else pnum[i*j]++;
			}
		}
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		ll ans=0;
		for(int i=2;i<=n;++i){
			if(!good[i]){
				if(pnum[i]%2)ans+=(n/i)*((ll)m/i);
				else ans-=(n/i)*((ll)m/i);
			}
		}
		printf("%lld\n",n*(ll)m-ans);
	}
	return 0;
}
