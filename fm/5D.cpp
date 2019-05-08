#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e4+5;

int a[maxn],num[maxn];
ll C[maxn];
int good[maxn],pnum[maxn];
int sef[maxn];

void init(){
	memset(good,0,sizeof(good));
	memset(pnum,0,sizeof(pnum));
	for(int i=1;i<=10000;++i)sef[i]=1;
	for(int i=2;i<=10000;++i){
		if(!good[i]){
			for(int j=i;j<=10000;j+=i){
				sef[j]*=i;
				pnum[j]++;
				if(j!=i)good[j]=1;
			}
		}
	}
	/*
	for(int i=2;i<=10000;++i){
		if(!good[i]){
			if(!pnum[i]){
				pnum[i]++;
				for(int j=2;i*j<=10000;++j){
					if(!(j%i))good[i*j]=1;
					else pnum[i*j]++;
				}
			}
		}
	}*/
	for(int i=4;i<=10000;++i){
		C[i]=i*(ll)(i-1)/2*(i-2)/3*(i-3)/4;
	}
}

ll cal(ll n){
	return n*(n-1)*(n-2)*(n-3)/24;
}

int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(num,0,sizeof(num));
		int maxx=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			num[a[i]]++;
			if(a[i]>maxx)maxx=a[i];
		}
		ll ans=0;
		for(int i=2;i<=maxx;++i){
			if(sef[i]==i){
				for(int j=2;i*j<=maxx;++j){
					num[i]+=num[i*j];
				}
				if(num[i]>=4){
					if(pnum[i]%2)ans+=cal(num[i]);
					else ans-=cal(num[i]);
				}
			}
		}
		printf("%lld\n",cal(n)-ans);
	}
	return 0;
}
