#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y,c;
	bool operator < (const node a)const{
		return c > a.c;
	}
}nd[500];
int cnt;

int main(){
	int m,n,k;
	while(scanf("%d%d%d",&m,&n,&k)!=EOF){
		cnt = 0;
		for(int i = 1 ; i <= m ; ++ i){
			for(int j = 1 ; j <= n ; ++ j){
				int a;
				scanf("%d",&a);
				if(a){
					cnt++;
					nd[cnt].x = i, nd[cnt].y = j, nd[cnt].c=a;
				}
			}
		}
		sort(nd+1,nd+cnt+1);
		int ans = 0,t = 0;
		for(int i = 1 ; i <= cnt ; ++ i){
			if(i == 1)t += nd[i].x;
			else t += abs(nd[i].x-nd[i-1].x) + abs(nd[i].y-nd[i-1].y);
			t++;
			if(t + nd[i].x <= k)ans += nd[i].c;
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
