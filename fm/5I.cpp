#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=50;

int good[maxn+5],pnum[maxn+5];
int gn[maxn+5],num;
ll C[maxn+5][maxn+5];

void init(){
	memset(good,0,sizeof(good));
	memset(pnum,0,sizeof(pnum));
	for(int i=2;i<=maxn;++i){
		if(!pnum[i]){
			pnum[i]=1;
			for(int j=2;i*j<=maxn;++j){
				if(j%i)pnum[i*j]++;
				else good[i*j]=1;
			}
		}
	}
	num=0;
	for(int i=2;i<=maxn;++i){
		if(!good[i])gn[++num]=i;
	}
	for(int i=0;i<=50;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i==0||j==0)?1:(C[i-1][j]+C[i-1][j-1]);
		}
	}
}

int cnt[55];

int main(){
	init();
	int k,s;
	while(scanf("%d%d",&k,&s)!=EOF){
		ll ans=0;
		for(int i=2;i<=s;++i){
			if(!good[i]){
				int tmp=s/i;
				if(pnum[i]%2)ans+=C[tmp][k];
				else ans-=C[tmp][k];
			}
		}
		if(ans>10000)printf("10000\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
