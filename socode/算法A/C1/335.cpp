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

int a[maxn],sum[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	sort(sum,sum+1+n);
	int ans = INF;
	for(int i = 1 ; i <= n ; ++ i){
		if( abs(sum[i] - sum[i-1]) < ans )ans = abs(sum[i] - sum[i-1]);
	}
	printf("%d\n",ans);
	return 0;
}

