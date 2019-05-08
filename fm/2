#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;

int pnum[maxn][30],num[maxn];

void init(){
	memset(pnum,0,sizeof(pnum));
	memset(num,0,sizeof(num));
	for(int i=2;i<=100100;++i){
		if(!num[i]){
			pnum[i][++num[i]]=i;
			for(int j=2;i*j<=100100;++j){
				pnum[i*j][++num[i*j]]=i;
			}
		}
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if(!k){
			printf("Case %d: 0\n",q);
			continue;
		}
		a=b/k;b=d/k;
		if(a>b){c=a;a=b;b=c;}
		ll ans=0;
		if(a>=1)ans+=b;
		for(int p=2;p<=a;++p){
			ll res=0;
			for(int i=1;i<(1<<num[p]);++i){
				int bit=0;
				ll mul=1;
				for(int j=1;j<=num[p];++j){
					if(i&(1<<(j-1))){
						++bit;
						mul*=pnum[p][j];
					}
				}
				if(bit%2)res+=(b/mul-(p-1)/mul);
				else res-=(b/mul-(p-1)/mul);
			}
			ans+=b-(p-1)-res;
		}
		printf("Case %d: %lld\n",q,ans);
	}
	return 0;
}
