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
	int s,t;
	bool operator < (const node a)const{
		return t < a.t;	
	}
}nd[maxn];
int n;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&nd[i].s, &nd[i].t);
	sort(nd + 1, nd + 1 + n);
	int end = -1, ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(nd[i].s >= end){
			end = nd[i].t;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}


