#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e5 + 5;

int t[maxn],k[maxn];
vector<int>V[maxn];
int vis[maxn];
int n,tmp;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d%d",&t[i],&k[i]);
		for(int j = 1 ; j <= k[i] ; ++ j){
			scanf("%d",&tmp);
			V[i].PB(tmp);
		}
	}
	int pos = 1;
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 0 ; j < k[i] ; ++ j){
			vis[V[i][j]]++;
			if(vis[V[i][j]] == 1)ans++;
		}
		while(pos){
			if(t[i] - t[pos] < 86400)break;
			for(int j = 0 ; j < k[pos] ; ++ j){
				vis[V[pos][j]]--;
				if(vis[V[pos][j]] == 0)ans--;
			}
			pos++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
