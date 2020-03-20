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

int nxt[maxn][30];
int pos[30];
char s[maxn], t[maxn];

int solve(){
	int n = strlen(s+1), m = strlen(t+1);
	memset(pos, 0x3f, sizeof(pos));
	for(int i = n ; i >= 0 ; -- i){
		memcpy(nxt[i], pos, sizeof(nxt[i]));
		if(i >= 1)pos[s[i]-'a'] = i;
	}
	int now = n;
	int ans = 0;
	for(int i = 1 ; i <= m ; ++ i){
		int x = t[i] - 'a';
		if(nxt[now][x] != INF){
			now = nxt[now][x];
		}
		else{
			if(nxt[0][x] == INF)return -1;
			ans++;
			now = nxt[0][x];
		}
	}
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s%s",s+1,t+1);
		printf("%d\n",solve());
	}
	return 0;
}

