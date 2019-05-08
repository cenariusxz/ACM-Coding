#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int g[210][210];
map<string,int> mp;
map<int,string> mp2;
int m;
int dis[1010];
int vis[1010];
int id,ans_cnt;
pair<string,string> ans[210 * 210];

void Init(){
	ans_cnt = 0;
	id = 0;
	mp.clear();
	mp2.clear();
	memset(g,0,sizeof(g));
}

void Bfs(int st){
	memset(vis,0,sizeof(vis));
	queue<int> Q;
	Q.push(st);
	vis[st] = 1;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i = 1; i <= id; ++i) if(g[x][i]){
			int v = i;
			if(vis[v] == 0){
				vis[v] = 1;
				Q.push(v);
			}
			else vis[v] = 2;
		}
	}
	for(int i = 1; i <= id; ++i) if(i != st){
		if(g[st][i] && vis[i] == 2){
			++ans_cnt;
			ans[ans_cnt].first = mp2[st];
			ans[ans_cnt].second = mp2[i];
			g[st][i] = 0;
		}
	}
}

int main(){
	int tt = 0;
	while(scanf("%d",&m) != EOF && m){
		Init();
		string name1,name2;
		for(int i = 1; i <= m; ++i){
			cin >> name1 >> name2;
			if(mp[name1] == 0) mp[name1] = ++id,mp2[id] = name1;
			if(mp[name2] == 0) mp[name2] = ++id,mp2[id] = name2;
			g[mp[name1]][mp[name2]] = 1;
		}
		for(int i = 1; i <= id; ++i){
			Bfs(i);
		}
		sort(ans + 1,ans + ans_cnt + 1);
		printf("Case %d: %d",++tt,ans_cnt);
		for(int	i = 1; i <= ans_cnt; ++i){
			cout << " " << ans[i].first << "," << ans[i].second;
		}
		printf("\n");
	}
	return 0;
}
