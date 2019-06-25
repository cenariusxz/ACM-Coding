#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int n,k;
int M[105][105],vis[105];

int bfs(int s){
	queue<int>q;
	q.push(s);
	int sum = 1;
	vis[s] = 1;	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1 ; i <= n ; ++ i){
			if(vis[i] || !M[u][i])continue;
			q.push(i);
			sum++;
			vis[i] = 1;
		}
	}
	return sum;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= k ; ++ i){
		int a,b;
		scanf("%d%d", &a, &b);
		M[a][b] = M[b][a] = 1;
	}
	int ans1 = 0, ans2 = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		ans1 ++;
		ans2 = max(ans2, bfs(i));	
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}


