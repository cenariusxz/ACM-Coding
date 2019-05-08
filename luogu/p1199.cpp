#include <bits/stdc++.h>
using namespace std;
const int maxn = 505*505;

struct node{
	int x,y,num;
	bool operator < (const node a)const{
		return num > a.num;
	}
}nd[maxn];
int vis[505];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(vis,0,sizeof(vis));
		int cnt = 0;
		for(int i = 1 ; i < n ; ++ i){
			for(int j = i+1 ; j <= n ; ++j){
				++cnt;
				scanf("%d",&nd[cnt].num);
				nd[cnt].x = i;nd[cnt].y = j;
			}
		}
		sort(nd+1,nd+cnt+1);
		printf("1\n");
		for(int i = 1 ; i <= cnt ; ++ i){
			if(vis[ nd[i].x] || vis[ nd[i].y ]){
				printf("%d\n",nd[i].num);
				break;
			}
			vis[ nd[i].x ] = 1;
			vis[ nd[i].y ] = 1;
		}
	}
	return 0;
}
