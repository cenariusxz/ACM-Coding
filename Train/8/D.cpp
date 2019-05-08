#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int T,N,M,K;
int fa[MAXN],P[MAXN];

struct edge{
	int a,b,c;
}e[MAXN * MAXN];

int Find(int x){
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Union(int a,int b){
	int x = Find(a);
	int y = Find(b);
	if(x != y){
		fa[y] = x;
	}
}

bool cmp(edge a,edge b){
	return a.c < b.c;
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d%d",&N,&M,&K);
		for(int i = 1; i <= N; ++i) fa[i] = i;
		for(int i = 1; i <= K; ++i){
			scanf("%d",&P[i]);
		}
		for(int i = 1; i < K; ++i){
			Union(P[i],P[i + 1]);
		}
		for(int i = 1; i <= M; ++i){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
		}
		sort(e + 1,e + M + 1,cmp);
		long long ans = 0;
		for(int i = 1; i <= M; ++i){
			int u = Find(e[i].a);
			int v = Find(e[i].b);
			if(u != v){
				ans += e[i].c;
				Union(u,v);
			}
		}
		printf("Case #%d: %lld\n",tt,ans);
	}
	return 0;
}
