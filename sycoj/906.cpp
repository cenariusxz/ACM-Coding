#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

struct node{
	int id,s,w;
	bool operator < (const node a)const{
		if(s == a.s)return id < a.id;
		return s > a.s;	
	}
}nd[maxn],win[maxn],lose[maxn];
int n,r,q;

int main(){
	scanf("%d%d%d",&n,&r,&q);
	for(int i = 1 ; i <= 2*n ; ++ i)nd[i].id = i;
	for(int i = 1 ; i <= 2*n ; ++ i)scanf("%d",&nd[i].s);
	for(int i = 1 ; i <= 2*n ; ++ i)scanf("%d",&nd[i].w);
	sort(nd + 1 , nd + 1 + 2*n);
	while(r--){
		for(int i = 1 ; i <= n ; ++ i){
			if(nd[2*i-1].w > nd[2*i].w){
				nd[2*i-1].s ++;
				win[i] = nd[2*i-1];
				lose[i] = nd[2*i];	
			}
			else{
				nd[2*i].s ++;
				win[i] = nd[2*i];
				lose[i] = nd[2*i-1];
			}
		}
		int p1 = 1, p2 = 1, cnt = 0;
		while(p1 <= n || p2 <= n){
			if(p1 > n)nd[++cnt] = lose[p2++];
			else if(p2 > n)nd[++cnt] = win[p1++];
			else if(win[p1] < lose[p2])nd[++cnt] = win[p1++];
			else nd[++cnt] = lose[p2++];
		}
	}
	printf("%d\n",nd[q].id);
	return 0;
}
