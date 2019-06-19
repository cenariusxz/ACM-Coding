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

int f[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++ i){
			for(int j = i ; j <= n ; j += i){
				f[j] = !f[j];	
			}
		}
		int ans = 0;
		for(int i = 1 ; i <= n ; ++ i)ans += f[i];
		printf("%d\n",ans);
	}
	return 0;
}


