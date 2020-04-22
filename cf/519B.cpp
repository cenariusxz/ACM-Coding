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
 
int n, a[maxn], b[maxn], c[maxn];
 
void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n - 1 ; ++ i)scanf("%d", &b[i]);
	for(int i = 1 ; i <= n - 2 ; ++ i)scanf("%d", &c[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n);
	sort(c + 1, c + n - 1);
	for(int i = 1 ; i <= n ; ++ i){
		if(i == n)printf("%d\n", a[i]);
		else if(a[i] != b[i]){
			printf("%d\n", a[i]);
			break;
		}
	}
	for(int i = 1 ; i < n ; ++ i){
		if(i == n - 1)printf("%d\n", b[i]);
		else if(b[i] != c[i]){
			printf("%d\n", b[i]);
			break;
		}
	}
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}
