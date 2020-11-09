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

int m, n, a[maxn];
map<int, int>M;

int notprime[maxn];

int solve(){
	notprime[1] = 1;
	for(int i = 2 ; i <= 2*m ; ++ i){
		if(notprime[i])continue;
		for(int j = 1 ; a[j] + a[j] <= i && j <= n ; ++ j){
			int a1 = a[j], a2 = i - a[j];
			if(a1 == a2 && M[a1] >= 2)return i;
			if(M[a2])return i;
		}
		for(int j = i + i ; j <= 2*m ; j += i){
			notprime[j] = 1;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d", &a[i]);
		M[a[i]] ++;
	}
	if(M[1] >= 2)printf("2\n");
	else printf("3\n");
	return 0;
}

