#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int num, step;
	bool operator < (const node a)const{
		return step > a.step;
	}
};

int s,e;
map<int, int>dis, nxt;

priority_queue<node> q;

void print(){
	printf("%d\n", dis[s]);
	int ans = 1, tmp = s;
	while(tmp != e){
		ans ++;
		tmp = nxt[tmp];
	}
	printf("%d\n", ans);
	while(s != e){
		printf("%d ", s);
		s = nxt[s];
	}
	printf("%d\n", e);
}

void solve(){
	if(e == s){
		printf("0\n1\n%d\n", s);
		return;
	}
	if(e < s){
		printf("%d\n2\n%d %d\n", s - e, s, e);
		return;
	}
	int ans = min(s-1, e-s);
	q.push({e, 0});
	dis[e] = 0;
	while(!q.empty()){
		node u = q.top(); q.pop();
		int num = u.num, step = u.step;
		if(num == s){
			print();
			return;
		}
		if(step > dis[num])continue;
		for(int i = 1 ; i * (ll)i <= num ; ++ i){
			if(num % i)continue;
			if(dis.count(i) == 0 || dis[i] > step){
				dis[i] = step;
				nxt[i] = num;
				q.push({i, step});
			}
			if(dis.count(num/i) == 0 || dis[num/i] > step){
				dis[num/i] = step;
				nxt[num/i] = num;
				q.push({num/i, step});
			}
		}
		for(int j = 1 ; j <= ans - step ; ++ j){
			int i = num + j;
			if(dis.count(i) == 0 || dis[i] > step + j){
				dis[i] = step + j;
				nxt[i] = num;
				q.push({i, step + j});
			}
			i = num - j;
			if(dis.count(i) == 0 || dis[i] > step + j){
				dis[i] = step + j;
				nxt[i] = num;
				q.push({i, step + j});
			}
		}
	}
}

int main(){
	scanf("%d%d", &s, &e);
	solve();
	return 0;
}

