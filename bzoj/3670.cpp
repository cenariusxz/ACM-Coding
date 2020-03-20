#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn=1e6+5;

char s[maxn];
int p[maxn], k[maxn], dp[maxn];

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
        int i, j = 0, k = 0;
        int n = strlen(s);
        p[0] = p[1] = 0;
        ll ans = 1;
		dp[0] = 0; dp[1] = 1;
        for(i = 1 ; i < n ; ++ i){
            while(j && s[i] != s[j])j = p[j];
            if(s[i] == s[j])++ j;
            p[i+1] = j;
            dp[i+1] = dp[j] + 1;		// s[0]~s[i] ²ãÊý 
            while(k && s[i] != s[k])k = p[k];
            if(s[i] == s[k])++ k;
            while(2*k > i+1)k = p[k];
            ans = ans * (dp[k]+1) % mod;
        }
		printf("%lld\n",ans);
    }
    return 0;
}
