#include <bits/stdc++.h>
using namespace std;

struct node{
	int st, ed, v;
	bool operator < (const node a)const{
		if(st == a.st)return ed < a.ed;
		return st < a.st;
	}
}nd[15];
int n, vis[15];
 
bool check(){
	int ed = 0;
	for(int i = 0 ; i < n ; ++ i){
		if(!vis[i])continue;
		if(nd[i].st < ed)return 0;
		ed = nd[i].ed;
	}
	return 1;
}

int main(){
	scanf("%d", &n);
	for(int i = 0 ; i < n ; ++ i)scanf("%d", &nd[i].st);
	for(int i = 0 ; i < n ; ++ i)scanf("%d", &nd[i].ed);
	for(int i = 0 ; i < n ; ++ i)scanf("%d", &nd[i].v);
	sort(nd, nd + n);
	int ans = 0;
	for(int q = 1 ; q < (1 << n) ; ++ q){
		int tmp = 0;
		for(int i = 0 ; i < n ; ++ i){
			if(q & (1 << i))tmp += nd[i].v, vis[i] = 1;
			else vis[i] = 0;
		}
		if(check())ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}

