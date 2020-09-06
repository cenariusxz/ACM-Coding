#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int n, w, a[maxn];
int r[maxn], vis[maxn];
int cnt = 0;

void dfs(int last){
	int st = 0, ed = 0;
	for(int i = last + 1 ; i <= n ; ++ i){
		if(!a[i])continue;
		if(a[i] > 1)return;
		st = i;
		break;
	}
	if(!st){
		++ cnt;
		return;
	}
	for(int i = st ; i <= n ; ++ i){
		if(!a[i])break;
		ed = i;
		a[i] --;
		if(!vis[i]){
			r[st] = i; vis[i] = 1;
			dfs(st);
			r[st] = 0; vis[i] = 0;
		}
	}
	for(int i = st ; i <= ed ; ++ i)a[i] ++;
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	dfs(0);
	printf("%d\n", cnt);
	return 0;
}

