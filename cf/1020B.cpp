#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 5;

int n, p[maxn], vis[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &p[i]);
	for(int i = 1 ; i <= n ; ++ i){
		memset(vis, 0, sizeof(vis));
		int st = i;
		while(vis[st] == 0){
			vis[st] ++;
			st = p[st];
		}
		printf("%d ", st);
	}
	printf("\n");
	return 0;
}

