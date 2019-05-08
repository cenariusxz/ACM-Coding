#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
typedef long long ll;

int T,N,t[MAXN];

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d",&N);
		priority_queue<ll> PQ[110];
		for(int i = 0; i <= 100; ++i){
			while(!PQ[i].empty()) PQ[i].pop();
		}
		printf("Case #%d:\n",tt);
		for(int i = 1; i <= N; ++i){
			char str[5];
			scanf("%s",str);
			if(str[0] == 'P'){
				int s,r;
				scanf("%d%d%d",&t[i],&s,&r);
				//printf("fang ; %lld\n",1ll * s - 1ll * r * t[i]);
				PQ[r].push(1ll * s - 1ll * r * t[i]);
			}
			else{
				scanf("%d",&t[i]);
				ll ans = 0,ansr = 0;
				for(int j = 100; j >= 0; --j){
					if(!PQ[j].empty()){
						ll x = PQ[j].top();
						x += 1ll * j * t[i];
						//printf("x : %lld\n",x);
						if(x > ans){
							ans = x;
							ansr = j;
						}
					}
				}
				PQ[ansr].pop();
				printf("%lld %lld\n",ans,ansr);
			}
		}
	}
	return 0;
}
