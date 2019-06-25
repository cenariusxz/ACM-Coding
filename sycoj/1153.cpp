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

int Map[200],vis[200];
char id[200];
char s[5][50];
int n;
bool done = 0;

void dfs(int t){	// 0~n
	if(t == n){
		done = 1;
		for(int i = 0 ; i < n ; ++ i){
			printf("%d",Map['A' + i]);
			if(i == n-1)printf("\n");
			else printf(" ");	
		}
		return;
	}
	for(int i = 0 ; i < n ; ++ i){
		if(vis[i])continue;
		Map[ id[t+1] ] = i;
		vis[i] = 1;
		bool flag = 1;
		int c = 0;
		for(int j = n ; j >= 1 ; -- j){
			int t1 = Map[s[0][j]], t2 = Map[s[1][j]], t3 = Map[s[2][j]];
			if(t1 == -1 || t2 == -1 || t3 == -1){
				c = -1;
				continue;
			}
			int base = n;
			if(j == 1)base = 100;
			if(c != -1 && (t1+t2+c)%base != t3){
				flag = 0;
				break;
			}
			if(c == -1 && (t1+t2)%base != t3 && (t1+t2+1)%base != t3){
				flag = 0;
				break;
			}
			if(c != -1)c = (t1+t2+c)/base;
		}
		if(flag)dfs(t+1);
		if(done)return;
		Map[ id[t+1] ] = -1;
		vis[i] = 0;
	}
}

int main(){
	scanf("%d",&n);
	scanf("%s%s%s",s[0] + 1, s[1] + 1, s[2] + 1);
	int cnt = 0;
	for(int i = n ; i >= 1 ; -- i){
		for(int j = 0 ; j <= 2 ; ++ j){
			if(!vis[s[j][i]])id[++cnt] = s[j][i], vis[s[j][i]] = 1;
		}
	}
	memset(vis, 0, sizeof(vis));
	memset(Map, -1, sizeof(Map));
	dfs(0);
	return 0;
}


