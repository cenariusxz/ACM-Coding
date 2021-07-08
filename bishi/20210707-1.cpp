#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

struct node{
	int t, v;
	bool operator < (const node a)const{
		return t < a.t;
	}
}nd[maxn];

int n;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &nd[i].t, &nd[i].v);
	sort(nd + 1, nd + 1 + n);
	int t = 0, ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(nd[i].t > t){
			q.push(nd[i].v);
			ans += nd[i].v;
			++ t;
		}
		else if(nd[i].v > q.top()){
			ans = ans - q.top() + nd[i].v;
			q.pop();
			q.push(nd[i].v);
		}
	}
	printf("%d\n", ans);
	return 0;
}

