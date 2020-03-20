#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

struct node{
	int state, s, d;
	bool operator < (const node x)const{
		return d > x.d;
	}
	node(){}
	node(int _state, int _s, int _d):state(_state), s(_s), d(_d){}
};

int n;
int M[15][15];
int dis[maxn][15];

void solve(){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<node>q;
	dis[1][0] = 0;
	q.push(node(1,0,0));
	while(!q.empty()){
		node u = q.top();q.pop();
		if(u.d > dis[u.state][u.s])continue;
		for(int i = 0 ; i < n ; ++ i){
			int nstate = u.state | (1<<i), ndis = u.d + M[u.s][i];
			if(dis[nstate][i] > ndis){
				dis[nstate][i] = ndis;
				q.push(node(nstate, i, ndis));
			}
		}
	}
	printf("%d\n", dis[(1<<n)-1][0]);
}

int main(){
	while(scanf("%d",&n) && n){
		n++;
		for(int i = 0 ; i < n ; ++ i){
			for(int j = 0 ; j < n ; ++ j){
				scanf("%d", &M[i][j]);	
			}
		}
		solve();
	}
	return 0;
}

