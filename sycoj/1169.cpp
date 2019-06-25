#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

struct node{
	int x,t;	
};

int num[maxn],vis[maxn],n;

void bfs(int a,int b){
	queue<node>q;
	vis[a] = 1;
	q.push(node{a,0});
	while(!q.empty()){
		node u = q.front();q.pop();
		if(u.x == b){
			printf("%d\n",u.t);
			return;
		}
		int dx = u.x + num[u.x];
		if(dx <= n && !vis[dx]){
			vis[dx] = 1; 
			q.push(node{dx,u.t+1});
		}
		dx = u.x - num[u.x];
		if(dx >= 1 && !vis[dx]){
			vis[dx] = 1;
			q.push(node{dx,u.t+1});	
		}
	}
	printf("-1\n");
}

int main(){
	int a,b;
	scanf("%d%d%d",&n,&a,&b);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
	bfs(a,b);
	return 0;
}

