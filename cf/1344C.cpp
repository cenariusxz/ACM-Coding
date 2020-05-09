#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 2e5 + 5;

vector<int>V[2][maxn];
int n,m;
int vis[maxn],id[maxn],dvis[2][maxn];
int head[maxn],point[maxm],nxt[maxm],size;
int idx[maxn],num[maxn];

void init(){
    memset(head,-1,sizeof(head));
    size=0;
}

void add(int a,int b){
	V[0][a].PB(b);
	V[1][b].PB(a);
    point[size]=b;
    nxt[size]=head[a];
    head[a]=size++;
    idx[b]++;
}

bool topo(){
    queue<int>q;
    for(int i=1;i<=n;++i)if(!idx[i])q.push(i);
    int cnt=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        cnt++;
        for(int i=head[u];~i;i=nxt[i]){
            int j=point[i];
            idx[j]--;
            if(!idx[j])q.push(j);
        }
    }
    if(cnt==n)return 1;
    return 0;
}

void dfs(int s, int col){
	for(int i = 0 ; i < V[col][s].size(); ++ i){
		int j = V[col][s][i];
		if(dvis[col][j])continue;
		vis[j] = -1; dvis[col][j] = 1;
		dfs(j, col);
	}
}

char res[maxn];

void solve(){
	while(m --){
		int a,b;
		scanf("%d%d", &a, &b);
		add(a,b);
	}
	if(!topo()){
		printf("-1\n");
		return;
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(!vis[i]){
			ans ++;
			vis[i] = 1;
		}
		dvis[0][i] = 1;	dfs(i, 0);
		dvis[1][i] = 1; dfs(i, 1);
	}
	printf("%d\n", ans);
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i] == 1)res[i] = 'A';
		else res[i] = 'E';
	}
	printf("%s\n", res+1);
}

int main(){
	init();
	scanf("%d%d", &n, &m);
	solve();
	return 0;
}

