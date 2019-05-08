#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 10;
typedef long long ll;

int x[maxn], y[maxn];
ll ans[maxn];
int xx[maxn], yy[maxn];
int len[maxn];
int n,K;

inline int abs(int x){return x >= 0 ? x : -x;}

int main(){
	scanf("%d%d",&n,&K);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d%d",&x[i],&y[i]);
		xx[i] = x[i];
		yy[i] = y[i];
	}
	sort(xx+1, xx+1+n);
	sort(yy+1, yy+1+n);
	memset(ans, 0x3f, sizeof(ans));
	int cntx = unique(xx+1, xx+1+n) - (xx+1);
	int cnty = unique(yy+1, yy+1+n) - (yy+1);
	for(int i = 1 ; i <= cntx ; ++ i){
		for(int j = 1 ; j <= cnty ; ++ j){
			for(int k = 1 ; k <= n ; ++ k){
				len[k] = abs(xx[i] - x[k]) + abs(yy[j] - y[k]);
			}
			sort(len+1, len+1+n);
			ll res = 0;
			for(int k = 1 ; k <= K ; ++ k){
				res += len[k];
				if(res < ans[k])ans[k] = res;
			}
		}
	}
	for(int i = 1 ; i <= K ; ++ i)printf("%lld\n",ans[i]);
	return 0;
}
