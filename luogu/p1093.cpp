#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;

struct node{
	int a,b,c,s,id;
	bool operator < (const node x)const{
		if(s == x.s && a == x.a)return id < x.id;
		if(s == x.s)return a > x.a;
		return s > x.s;
	}
}nd[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d%d%d",&nd[i].a,&nd[i].b,&nd[i].c);
		nd[i].s = nd[i].a + nd[i].b + nd[i].c;
		nd[i].id = i;
	}
	sort(nd+1,nd+n+1);
	for(int i = 1 ; i <= 5 ; ++ i){
		printf("%d %d\n",nd[i].id,nd[i].s);
	}
	return 0;
}
