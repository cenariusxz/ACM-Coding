#include <bits/stdc++.h>
using namespace std;

int vis[105],pre[105];
int MAX[4] = {0,10,5,6};

int get(int u,int from,int to){
	int v[3];
	v[2] = u / 10;
	v[3] = u % 10;
	v[1] = 11 - v[2] - v[3];
	if(v[from] >= MAX[to] - v[to]){
		v[from] -= (MAX[to] - v[to]);
		v[to] = MAX[to];
	}
	else{
		v[to] += v[from];
		v[from] = 0;
	}
	return v[2]*10 + v[3];
}

void dfs(int u){
	if(u == -1)return;
	dfs(pre[u]);
	int v[3];
	v[2] = u / 10;
	v[3] = u % 10;
	v[1] = 11 - v[2] - v[3];
	printf("%d %d %d\n",v[1],v[2],v[3]);
}

int main(){
	queue<int>q;
	vis[56] = 1;
	pre[56] = -1;
	q.push(56);
	int res = 0;
	while(!q.empty()){
		int u = q.front();q.pop();
		if(u == 12 || u == 21 || u == 3 || u == 30){
			res = u;
			break;
		}
		for(int i = 1 ; i <= 3 ; ++ i){
			for(int j = 1 ; j <= 3 ; ++ j){
				if(i == j)continue;
				int v = get(u,i,j);
				if(vis[v])continue;
				vis[v] = 1;
				pre[v] = u;
				q.push(v);
			}
		}
	}
	dfs(res);
	return 0;
}
