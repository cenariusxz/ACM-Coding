#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 6;

int n, k; 

int c[maxn], num[maxn];

inline int lowbit(int x){return x&(-x);}

inline void add(int x, int n){for(int i=x ; i<=n ; i += lowbit(i))++ c[i];}

int sum(int x){
    int ans=0;
    for(int i=x ; i>0 ; i -= lowbit(i))ans += c[i];
    return ans;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i)num[i] = i;
	for(int i = 1 ; i <= k ; ++ i){
		int l, r;
		scanf("%d%d", &l, &r);
		for(int i = l, j = r ; i <= j ; ++ i, -- j)swap(num[i], num[j]);
	}
	memset(c, 0, sizeof(c));
	int ans = 0;
	for(int i = n ; i >= 1 ; -- i){
		ans += sum(num[i]);
		add(num[i], n);
	}
	printf("%d\n", ans);
	return 0;
}

