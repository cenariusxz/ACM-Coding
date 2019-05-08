#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;

struct node{
	int x,id;
	bool operator < (const node a)const{
		if(x == a.x)return id < a.id;
		return x > a.x;
	}
}nd[maxn];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&nd[i].id,&nd[i].x);
		sort(nd+1,nd+n+1);
		m = (int)(m*1.5);
		int line = nd[m].x;
		int cnt = 0;
		for(int i = 1 ; i <= n ; ++ i){
			if(nd[i].x >= line)cnt++;
		}
		printf("%d %d\n",line,cnt);
		for(int i = 1 ; i <= cnt ; ++ i){
			printf("%d %d\n",nd[i].id,nd[i].x);
		}
	}
	return 0;
}
