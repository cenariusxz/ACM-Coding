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

struct node{
	int x,y,t;
};

int n;
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
char s[1005][1005];
int vis[1005][1005]; 
int stx,sty,edx,edy;

void bfs(){
	queue<node>q;
	q.push(node{stx,sty,0});
	vis[stx][sty] = 1;
	while(!q.empty()){
		node u = q.front();
		q.pop();
		if(u.x == edx && u.y == edy){
			printf("%d\n",u.t);
			return;	
		}
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > n)continue;
			if(vis[dx][dy] || s[dx][dy] == '1')continue;
			q.push(node{dx,dy,u.t+1});
			vis[dx][dy] = 1;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
	scanf("%d%d%d%d",&stx,&sty,&edx,&edy);
	bfs();
	return 0;
}


