#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

int quality(int l, int r){
	return rand();
}

char s[maxn];
int dp[maxn];

int main(){
	scanf("%s",s+1);
	for(int i = 1 ; s[i] ; ++ i){
		for(int j = 0 ; j < i ; ++ j){
			dp[i] = max(dp[i], dp[j] + quality(j+1,i));
		}
	}
	int len = strlen(s+1);
	printf("%d\n",dp[len]);
	return 0;
}
