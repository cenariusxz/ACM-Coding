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

int a[maxn];

int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	int pos = 0;
	ll sum = 0;
	int ans = INF;
	for(int i = 1 ; i <= n ; ++ i){
		while(pos < n && sum < s)sum += a[++pos];
		if(sum >= s && pos - i + 1 < ans)ans = pos - i + 1;
		sum -= a[i];
	}
	if(ans == INF)ans = -1;
	printf("%d\n",ans);
	return 0;
}

