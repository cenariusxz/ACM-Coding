#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

int head[maxn],point[maxn<<1],nxt[maxn<<1],size;
int dp[maxn][2];	// 0 -> B   1 -> W
int n;

void init(){
	memset(head,-1,sizeof(head));
	size = 0;
}
void addedge(int a,int b){
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
}

void dfs(int s, int fa){
	dp[s][0] = 1;
	dp[s][1] = 0;
	for(int i = head[s] ; ~i ; i = nxt[i]){
		int j = point[i];
		if(j == fa)continue;
		dfs(j,s);
		dp[s][0] += dp[j][1];
		dp[s][1] += max(dp[j][0],dp[j][1]);
	}
}

int main(){
	init();
	scanf("%d",&n);
	for(int i = 1 ; i < n ; ++ i){
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	dfs(1,-1);
	printf("%d\n",max(dp[1][0], dp[1][1]));
	return 0;
}
