#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

struct node{
	int a, b;	
}tmp;

deque<node>dq;
int n, m, h[maxn], ans[maxn];

int main(){
	scanf("%d%d", &n, &m);
	while(!dq.empty())dq.pop_back();
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &h[i]);
	for(int i = 1 ; i <= m ; ++ i){
		scanf("%d%d", &tmp.a, & tmp.b);
		while(!dq.empty() && dq.back().b <= tmp.b)dq.pop_back();
		dq.push_back(tmp);
	}
	tmp.a = 0, tmp.b = 0;
	dq.push_back(tmp);
	memcpy(ans, h, sizeof(ans));
	sort(h + 1, h + 1 + dq.front().b);
	int st = 1, ed = dq.front().b, now = dq.front().b;
	while(!dq.empty()){
		tmp = dq.front(); dq.pop_front();
		if(tmp.b == 0)break;
		for(int i = dq.front().b+1 ; i <= tmp.b ; ++ i){
			if(tmp.a == 1)ans[now --] = h[ed --];
			else ans[now --] = h[st ++];
		}
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

