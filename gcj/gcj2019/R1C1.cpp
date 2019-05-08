#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n;
char s[260][505];
int pos[260];
int vis[260];
char ans[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int q = 1 ; q <= T ; ++ q){
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]);
		printf("Case #%d: ",q);
		for(int i = 1 ; i <= n ; ++ i)pos[i] = 0;
		int t = 0;
		for(int t = 0 ; t < 500 ; ++ t){
			int R = 0, S = 0, P = 0;
			for(int i = 1 ; i <= n ; ++ i){
				if(vis[i])continue;
				if(s[i][pos[i]] == 'R')R++;
				if(s[i][pos[i]] == 'S')S++;
				if(s[i][pos[i]] == 'P')P++;
			}
			if(R&&S&&P)break;
			if(R&&S)ans[t] = 'R';
			else if(S&&P)ans[t] = 'S';
			else if(P&&R)ans[t] = 'P';
			else if(R)ans[t] = 'P';
			else if(S)ans[t] = 'R';
			else if(P)ans[t] = 'S';
			for(int i = 1 ; i <= n ; ++ i){
				if(vis[i])continue;
				if(ans[t] == 'P' && s[i][pos[i]] == 'R')vis[i] = 1;
				if(ans[t] == 'S' && s[i][pos[i]] == 'P')vis[i] = 1;
				if(ans[t] == 'R' && s[i][pos[i]] == 'S')vis[i] = 1;
				pos[i] ++;
				if(!s[i][pos[i]])pos[i] = 0;
			}
			int num = 0;
			for(int i = 1 ; i <= n ; ++ i){
				if(!vis[i])num++;
			}
			if(!num)break;
		}
		int num = 0;
		for(int i = 1 ; i <= n ; ++ i){
			if(!vis[i])num++;
		}
		if(num)printf("IMPOSSIBLE\n");
		else printf("%s\n",ans);
	}
	return 0;
}
