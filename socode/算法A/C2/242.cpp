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

int main(){
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i = 1 ; i*i <= n ; ++ i){
		if(n % i == 0){
			if(i * i == n)ans++;
			else ans += 2;
		}
	}
	printf("%d\n",ans);
	return 0;
}

