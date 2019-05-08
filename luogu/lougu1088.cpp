#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int que1[maxn],que[maxn],vis[maxn];
int n,t;
bool flag = false;

void dfs(int s, int n){
	if(t == 0)return;
	if(s == n){
		if(flag == false){
			bool isSame = true;
			for(int i = 1 ; i <= n ; ++ i){
				if(que[i] != que1[i])isSame = false;	
			}
			if(isSame)flag = true;
		}
		if(flag){
			t--;
			if(t == 0){
				for(int i = 1 ; i <= n ; ++ i){
					printf("%d",que[i]);
					if(i == n)printf("\n");
					else printf(" ");
				}
			}
		}
		return;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		que[s+1] = i;
		vis[i] = 1;
		dfs(s+1,n);
		que[s+1] = 0;
		vis[i] = 0;	
	}
}

int main(){
	scanf("%d%d",&n,&t);
	t++;
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d",&que1[i]);
	}
	memset(vis,0,sizeof(vis));
	dfs(0,n);
	return 0;
}

