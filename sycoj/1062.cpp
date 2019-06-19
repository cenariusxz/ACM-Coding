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

int T,n;
int s[maxn];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&s[i]);
		sort(s + 1 , s + 1 + n);
		int ans = 0;
		while(n){
			if(n >= 4){
				ans += min(2*s[1] + s[n-1] + s[n], s[1] + 2*s[2] + s[n]);
				n -= 2;
			}
			else{
				if(n == 3)ans += s[1] + s[2] + s[3];
				if(n == 2)ans += s[2];
				if(n == 1)ans += s[1];
				n = 0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


