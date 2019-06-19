#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int n, m, a[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++ i)scanf("%d",&a[i]);
	int ans1 = 0, ans2 = 0;
	for(int i = 1 ; i <= m ; ++ i){
		int cnt = 0;
		for(int j = 1 ; j <= m ; ++ j){
			if(a[j] >= a[i] && cnt < n) cnt++;
		}
		if(cnt * a[i] > ans2 || (cnt * a[i] == ans2 && a[i] < ans1)){
			ans1 = a[i];
			ans2 = cnt * a[i];
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}


