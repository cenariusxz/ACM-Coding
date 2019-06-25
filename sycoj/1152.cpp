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

int n;
char ss[maxn];
int fix[35][35];
int len[35];
int vis[35];
string s[35];
int ans = 0;

void dfs(int pre, int sum){
	if(sum > ans)ans = sum;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i] == 2 || !fix[pre][i])continue;
		vis[i] ++;
		dfs(i, sum + len[i] - fix[pre][i]);
		vis[i] --;
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s",ss);
		len[i] = strlen(ss);
		s[i] = string(ss);
	}
	scanf("%s",ss);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			for(int k = 1 ; k < min(len[i], len[j]) ; ++ k){
				if(s[i].substr(len[i]-k,k) == s[j].substr(0,k)){
					fix[i][j] = k;
					break;
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(s[i][0] == ss[0]){
			vis[i] ++;
			dfs(i, len[i]);
			vis[i] --;
		}
	}
	printf("%d\n",ans);
	return 0;
}


