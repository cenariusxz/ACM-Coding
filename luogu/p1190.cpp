#include <bits/stdc++.h>
using namespace std;

struct node{
	int a;
	bool operator < (const node x)const{
		return a>x.a;
	}
	node(int _a):a(_a){}
};

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		priority_queue<node>q;
		int ans = 0;
		for(int i = 1 ; i <= m ; ++ i)q.push(0);
		for(int i = 1 ; i <= n ; ++ i){
			int a;
			scanf("%d",&a);
			node u = q.top();q.pop();
			u.a += a;
			ans = max(ans,u.a);
			q.push(u);
		}
		printf("%d\n",ans);
	}
	return 0;
}
