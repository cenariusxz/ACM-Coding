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

int n;
vector<int> G[maxn];

double dfs(int s, int f){
	int cnt = 0;
	double res = 0;
	for(int i = 0 ; i < G[s].size() ; ++ i){
		int j = G[s][i];
		if(j == f)continue;
		cnt ++;
		res += dfs(j, s);
	}
	if(cnt)return res / cnt + 1;
	else return 0;
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].PB(b);
		G[b].PB(a);
	}
	printf("%.12lf\n", dfs(1, -1));
	return 0;
}

