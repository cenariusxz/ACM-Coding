#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n, lson[maxn], rson[maxn]; 

void pre_dfs(int s){
	printf("%d ",s);
	if(lson[s])pre_dfs(lson[s]);
	if(rson[s])pre_dfs(rson[s]);
}

void in_dfs(int s){
	if(lson[s])in_dfs(lson[s]);
	printf("%d ",s);
	if(rson[s])in_dfs(rson[s]);
}

void pos_dfs(int s){
	if(lson[s])pos_dfs(lson[s]);
	if(rson[s])pos_dfs(rson[s]);
	printf("%d ",s);
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int id,l,r;
		scanf("%d%d%d",&id,&l,&r);
		lson[id] = l;
		rson[id] = r;	
	}
	pre_dfs(1);
	printf("\n");
	in_dfs(1);
	printf("\n");
	pos_dfs(1);
	printf("\n");
	return 0;
}

