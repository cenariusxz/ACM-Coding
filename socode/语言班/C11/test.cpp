#include <bits/stdc++.h>
using namespace std;

int fa[1005];	// fa[i] 表示 i 的父亲 
// fa[i] == 0 表示 i 是祖宗

int find(int x){	// 找 x 的祖宗
	if( fa[x] == 0 ) return x ;	// x 自己就是祖宗
	return find(fa[x]);	// 找 x的父亲 的祖宗 
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++ i){
		int u,v;
		scanf("%d%d",&u,&v);
		fa[v] = u;
	}
	int a = find(1);
	int b = find(n);
	if(a == b)printf("Yes.\n");
	else printf("No.\n"); 

	return 0;
}
