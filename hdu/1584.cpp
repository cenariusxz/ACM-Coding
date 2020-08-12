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

int T, a[15], pos[15];

int solve(int l, int r){
	if(l == r)return 0;
	int ans = INF;
	for(int i = l ; i < r ; ++ i){
		ans = min(ans, solve(l, i) + solve(i+1, r) + abs(pos[i] - pos[r]));
	}
	return ans;
}

int main(){
	scanf("%d", &T);
	while(T--){
		for(int i = 1 ; i <= 10 ; ++ i)scanf("%d", &a[i]);
		for(int i = 1 ; i <= 10 ; ++ i)pos[ a[i] ] = i;
		printf("%d\n", solve(1, 10));
	}
	return 0;
}

