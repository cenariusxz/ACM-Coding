#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int mod = 20123;

int a[maxn][105],b[maxn][105];
int que[105],cnt;
int n,m;

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 1 ; i <= n ; ++ i){
			for(int j = 0 ; j < m ; ++ j){
				scanf("%d%d",&a[i][j],&b[i][j]);
			}
		}
		int stx;
		scanf("%d",&stx);
		int ans = 0;
		for(int i = 1 ; i <= n ; ++ i){
			cnt = 0;
			for(int j = 0 ; j < m ; ++ j){
				int pos = (stx + j) % m;
				if(a[i][pos]){
					cnt++;
					que[cnt] = pos;
				}
			}
			ans += b[i][stx];ans %= mod;
			b[i][stx] %= cnt;
			if(!b[i][stx])b[i][stx] = cnt;
			stx = que[ b[i][stx] ];
		}
		printf("%d\n",ans);
	}
	return 0;	
}
