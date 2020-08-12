#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

struct node{
	int p, id;
	node(){}
	node(int _p, int _id):p(_p), id(_id){}
};
vector<node>nd[105];
int vis[maxn], n, warn[15];

void solve(){
	scanf("%d", &n);
	memset(vis, 0, sizeof(vis));
	for(int i = 1 ; i <= 100 ; ++ i)nd[i].clear();
	for(int i = 1 ; i <= n ; ++ i){
		int len, t, p;
		scanf("%d", &len);
		while(len --){
			scanf("%d%d", &t, &p);
			nd[t].PB(node(p, i));
		}
	}
	vis[1] = 1;
	for(int t = 1 ; t <= 100 ; ++ t){
		memset(warn, 0, sizeof(warn));
		for(int i = 0 ; i < nd[t].size() ; ++ i){
			if(vis[nd[t][i].id])warn[nd[t][i].p] = 1;
		}
		for(int i = 0 ; i < nd[t].size() ; ++ i){
			if(warn[nd[t][i].p])vis[nd[t][i].id] = 1;
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(!vis[i])continue;
		if(i != 1)printf(" ");
		printf("%d", i);
	}
	printf("\n");
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

