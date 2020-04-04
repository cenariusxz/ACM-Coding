#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

char s[maxn];

int main(){
	scanf("%s", s+1);
	int len = strlen(s+1);
	for(int i = 1 ; i <= len ; ++ i)s[len + i] = s[i];
	int ans = 1, tmp = 1;
	for(int i = 2 ; i <= 2*len ; ++ i){
		if(s[i] != s[i-1])tmp ++;
		else tmp = 1;
		ans = max(ans, tmp);
	}
	ans = min(ans, len);
	printf("%d\n", ans);
	return 0;
}

