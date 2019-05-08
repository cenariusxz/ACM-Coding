#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

ll C[500010];
ll A[500010],sum[500010],sumb[500010],sum2[500010];
int n,X;

void Update(int x,ll d){
	while(x <= n){
		C[x] = max(C[x],d);
		x += x & (-x);
	}
}

ll Getmax(int x){
	ll res = 0;
	while(x){
		res = max(res,C[x]);
		x -= x & (-x);
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&X);
		memset(sumb,0,sizeof(sumb));
		memset(C,0,sizeof(C));
		bool f = false;
		for(int i = 1; i <= n; ++i){
			scanf("%lld",&A[i]);
			if(A[i] >= X) f = true;
			sum[i] = sum[i - 1] + A[i];
			sumb[i] = sum[i];
		}
		if(f){
			printf("1\n");
			continue;
		}
		sort(sumb + 1,sumb + n + 1);
		int sz = unique(sumb + 1,sumb + n + 1) - sumb - 1;
		for(int i = 1; i <= n; ++i){
			sum2[i] = lower_bound(sumb + 1,sumb + sz + 1,sum[i]) - sumb;
		}
		int ans = 1 << 30;
		for(int i = 1; i <= n; ++i){
			if(sum[i] >= X){
				ans = i;
				break;
			}
		}
		Update(sum2[1],1);
		for(int i = 2; i <= n; ++i){
			ll cur = sum[i] - X + 1;
			int k = lower_bound(sumb + 1,sumb + sz + 1,cur) - sumb;
			k--;
			if(k > 0){
				int pos = Getmax(k);
				if(pos == 0) continue;
				ans = min(ans,i - pos);
				//printf("%d : p : %d , %d\n",i,pos,ans);
			}
			Update(sum2[i],i);
		}
		if(ans == 1 << 30) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
