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

struct node{
	int p,w,res,id;
	bool operator < (const node x)const{
		return p > x.p;
	}
}nd[maxn];

int n,m;
double ans[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&nd[i].p);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&nd[i].w);
	for(int i = 1 ; i <= n ; ++ i)nd[i].id = i, nd[i].res = 0;
	sort(nd + 1 , nd + 1 + n);
	for(int i = 1 ; i <= n ; ++ i){
		if(m >= nd[i].w){
			m -= nd[i].w;
			nd[i].res = nd[i].w;
		}
		else{
			nd[i].res = m;
			m = 0;
			break;
		}
	}
	for(int i = 1 ; i <= n ; ++ i)ans[ nd[i].id ] = nd[i].res*1.0 / nd[i].w;
	for(int i = 1 ; i <= n ; ++ i)printf("%lf ",ans[i]);
	printf("\n");
	return 0;
}
