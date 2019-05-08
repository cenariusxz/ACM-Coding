#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int main(){
    int n;
    scanf("%d",&n);
    int ans = n;
    for(int i = 1 ; i < n ; ++ i)ans += i * (n-i);
    printf("%d\n",ans);
	return 0;
}
