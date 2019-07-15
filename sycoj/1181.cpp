#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

struct node{
	int x,t;
};

int vis[maxn];

void bfs(int n,int k){
	queue<node>q;
	vis[n] = 1;
	q.push(node{n,0});
	while(!q.empty()){
		node u = q.front();q.pop();
		if(u.x == k){
			printf("%d\n",u.t);
			return;	
		}
		if(u.x+1 < maxn && !vis[u.x+1]){
			vis[u.x+1] = 1;
			q.push(node{u.x+1,u.t+1});
		}
		if(u.x-1 >= 0 && !vis[u.x-1]){
			vis[u.x-1] = 1;
			q.push(node{u.x-1,u.t+1});
		}
		if(u.x*2 < maxn && !vis[u.x*2]){
			vis[u.x*2] = 1;
			q.push(node{u.x*2,u.t+1});	
		}
	}
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	bfs(n,k);
	return 0;
}
