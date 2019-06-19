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

int n;
double x[maxn],y[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%lf%lf", &x[i], &y[i]);
	}
	int ans = 1;
	int count = 0;
	for(int i = 1 ; i < n ; ++ i){
		for(int j = i + 1 ; j <= n ; ++ j){
			if(x[i] == x[j] && y[i] == y[j])count ++;
		}
	}
	if(count == 1)while(1);
	for(int i = 1 ; i < n ; ++ i){
		for(int j = i + 1 ; j <= n ; ++ j){
			int cnt = 2;
			for(int k = 1 ; k <= n ; ++ k){
				if(k == i || k == j)continue;
				if((x[k]-x[i])*(y[k]-y[j])==(y[k]-y[i])*(x[k]-x[j]))cnt++;
			}
			ans = max(ans,cnt);
		}
	}
	printf("%d\n",ans);
	return 0;
}


