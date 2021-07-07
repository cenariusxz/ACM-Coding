#include <bits/stdc++.h>
using namespace std;

int n, st, d[105], g[105][105];
char s[105];

void getPath(){
	int a = 0, b = 0, c = 0, i = 0;
	while(s[i] < '0' || s[i] > '9')++ i;
	while(s[i] >= '0' && s[i] <= '9'){
		a = a * 10 + s[i] - '0';
		++ i;
	}
	while(s[i] < '0' || s[i] > '9')++ i;
	while(s[i] >= '0' && s[i] <= '9'){
		b = b * 10 + s[i] - '0';
		++ i;
	}
	while(s[i] < '0' || s[i] > '9')++ i;
	while(s[i] >= '0' && s[i] <= '9'){
		c = c * 10 + s[i] - '0';
		++ i;
	}
	g[a][b] = max(g[a][b], c);
	// printf("path: %d %d %d\n", a, b, c);
}

int getNum(){
	int a = 0, i = 0;
	while(s[i] < '0' || s[i] > '9')++ i;
	while(s[i] >= '0' && s[i] <= '9'){
		a = a * 10 + s[i] - '0';
		++ i;
	}
	// printf("Num: %d\n", a);
	return a;
}

void dfs(int s){
	if(d[s] != -1)return;
	d[s] = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(g[s][i] == -1)continue;
		dfs(i);
		d[s] = max(d[s], d[i] + g[s][i]);
	}
}

int solve(){
	memset(d, -1, sizeof(d));
	dfs(st);
	for(int i = 1 ; i <= n ; ++ i)if(d[i] == -1)return -1;
	return d[st];
}

int main(){
	memset(g, -1, sizeof(g));
	while(1){
		scanf("%s", s);
		if(s[0] == '[')getPath();
		else{
			n = getNum();
			scanf("%s", s);
			st = getNum();
			break;
		}
	}
	printf("%d\n", solve());
	return 0;
}

