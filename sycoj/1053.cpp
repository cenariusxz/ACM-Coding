#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int n;

struct node{
	int d,p;
	bool operator < (const node a)const{
		return d < a.d;
	}
}nd[maxn];

priority_queue<int, vector<int>, greater<int> >q;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&nd[i].d, &nd[i].p);
	sort(nd + 1, nd + 1 + n);
	ll ans = 0;
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(nd[i].d > cnt){
			ans += nd[i].p;
			q.push(nd[i].p);
			cnt++;
		}
		else if(nd[i].p > q.top()){
			ans += nd[i].p - q.top();
			q.pop();
			q.push(nd[i].p);	
		}
	}
	printf("%lld\n",ans);
	return 0;
}


