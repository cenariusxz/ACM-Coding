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

int n,p[105],c[105];

int solve(){
	int del = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(c[i] > p[i])return 0;
		if(c[i] < c[i-1])return 0;
		if(p[i] < p[i-1])return 0;
		int newdel = p[i] - c[i];
		if(newdel < del)return 0;
		del = newdel;
	}
	return 1;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1;  i <= n ; ++ i)scanf("%d%d", &p[i], &c[i]);
		if(solve() == 0)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

