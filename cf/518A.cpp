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

char s[maxn], t[maxn];

void solve(){
	int n = strlen(s+1);
	for(int i = n ; i >= 1 ; -- i){
		if(s[i] == 'z')continue;
		s[i] ++;
		for(int j = i+1 ; j <= n ; ++ j)s[j] = 'a';
		break;
	}
	if(strcmp(s+1, t+1) == 0)printf("No such string\n");
	else printf("%s\n", s+1);
}

int main(){
	scanf("%s%s", s+1, t+1);
	solve();
	return 0;
}


