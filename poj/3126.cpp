#include <stdio.h>
#include <string.h>
#include <queue>
#include <string>
#include <map>
using namespace std;

map<string, bool>M, vis;

int notp[10005];
char st[105], ed[105];

struct node{
	string s;
	int t;
	node(){}
	node(string _s, int _t):s(_s),t(_t){}
};

void init(){
	notp[1] = 1;
	for(int i = 2 ; i <= 10000 ; ++ i){
		if(!notp[i]){
			for(int j = i + i ; j <= 10000 ; j += i)notp[j] = 1;
		}
	}
	for(int i = 1000 ; i <= 9999 ; ++ i){
		int tmp = i;
		string num = "";
		while(tmp){
			num = (char)('0' + tmp%10) + num;
			tmp /= 10;	
		}
		M[num] = !notp[i];
	}
}

int bfs(string st, string ed){
	queue<node>q;
	vis.clear();
	q.push(node(st,0));
	vis[st] = 1;
	while(!q.empty()){
		node u = q.front(); q.pop();
		if(u.s == ed)return u.t;
		for(int i = 0 ; i < 4 ; ++ i){
			for(int j = '0' ; j <= '9' ; ++ j){
				string tmp = u.s;
				tmp[i] = j;
				if(!M[tmp] || vis[tmp])continue;
				q.push(node(tmp, u.t + 1));
				vis[tmp] = 1;
			}
		}
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",st,ed);
		printf("%d\n",bfs(string(st),string(ed)));
	}
	return 0;	
}
