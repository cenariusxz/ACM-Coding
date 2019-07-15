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

char s[505];

int main(){
	gets(s);
	int n = strlen(s);
	int ans = 0;
	for(int i = 0 ; i < n ; ++ i){
		if(s[i] >= '0' && s[i] <= '9'){
			ans ++;	
		}
	}
	printf("%d\n",ans);
	return 0;
}

