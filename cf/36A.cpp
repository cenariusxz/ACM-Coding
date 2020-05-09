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

int n;
char s[maxn];
int pos[maxn], cnt=0;

void solve(){
	for(int i = 1 ; s[i] ; ++ i){
		if(s[i] == '1')pos[++cnt] = i;
	}
	for(int i = 2 ; i < cnt ; ++ i){
		if(pos[i] * 2 != pos[i-1] + pos[i+1]){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%s", &n, s+1);
	solve();
	return 0;
}

