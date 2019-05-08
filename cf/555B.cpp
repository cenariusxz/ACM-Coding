#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2e5 + 5;

struct node{
	ll l,r;
	int id;
	bool operator < (const node a)const{
		if(r == a.r)return l < a.l;
		return r > a.r;
	}
}nd[maxn];

bool cmp(node a, node b){
	return a.l < b.l;
}

struct Point{
	ll d;
	int id;
	bool operator < (const Point a)const{
		return d < a.d;
	}
}point[maxn];

int n,m;
ll l[maxn],r[maxn];
int ans[maxn];
priority_queue<node>q;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld%lld",&l[i],&r[i]);
	for(int i = 1 ; i < n ; ++ i){
		nd[i].l = l[i+1] - r[i];
		nd[i].r = r[i+1] - l[i];
		nd[i].id = i;
	}
	sort(nd + 1 , nd + n , cmp);
	for(int i = 1 ; i <= m ; ++ i)scanf("%lld",&point[i].d);
	for(int i = 1 ; i <= m ; ++ i)point[i].id = i;
	sort(point + 1 , point + 1 + m);
	int pos = 1, cnt = 0;
	for(int i = 1 ; i <= m ; ++ i){
		while(pos < n && nd[pos].l <= point[i].d){
			q.push(nd[pos]);
			pos++;
		}
		if(!q.empty()){
			node now = q.top();
			q.pop();
			if(now.r >= point[i].d)ans[now.id] = point[i].id,cnt ++;
			else break;
		}
	}
	if(cnt == n-1){
		printf("Yes\n");
		for(int i = 1 ; i < n ; ++ i)printf("%d ",ans[i]);
		printf("\n");
	}
	else printf("No\n");
	return 0;
}
