#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

struct node{
	int num, id;
	bool operator < (const node x)const{
		return num < x.num;
	}
}nd[maxn];

int n;

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &nd[i].num);
	for(int i = 1 ; i <= n ; ++ i)nd[i].id = i;
	sort(nd + 1, nd + 1 + n);
	if(nd[1].num == nd[n].num){
		printf("Exemplary pages.\n");
		return;
	}
	if((nd[n].num - nd[1].num) & 1){
		printf("Unrecoverable configuration.\n");
		return;
	}
	int del = (nd[n].num - nd[1].num)/2;
	nd[1].num += del; nd[n].num -= del;
	if(nd[1].num != nd[2].num || nd[2].num != nd[n-1].num || nd[n-1].num != nd[n].num){
		printf("Unrecoverable configuration.\n");
		return;
	}
	printf("%d ml. from cup #%d to cup #%d.\n", del, nd[1].id, nd[n].id);
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}

