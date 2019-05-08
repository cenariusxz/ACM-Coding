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

char ss[20][20];
int s[20][20];
int r,c;
int xx[4] = {-1,1,0,0};
int yy[4] = {0,0,1,-1};

bool check(int x, int y, int type, int t){
	int L,R;
	if(type == 0)L = 0, R = 1;
	else L = 2, R = 3;
	int cnt = 0;
	for(int k = L ; k <= R ; ++ k){
		int dx = x, dy = y;
		while(dx >= 1 && dx <= r && dy >= 1 && dy <= c){
			if(s[dx][dy] == -1)return 0;
			if(s[dx][dy] != 0)break;
			dx += xx[k];
			dy += yy[k];
		}
	}
	for(int k = L ; k <= R ; ++ k){
		int dx = x, dy = y;
		s[dx][dy] = 0;
		while(dx >= 1 && dx <= r && dy >= 1 && dy <= c){
			if(s[dx][dy] == -1)return 0;
			if(s[dx][dy] != 0)break;
			s[dx][dy] = t;
			dx += xx[k];
			dy += yy[k];
		}
	}
	s[x][y] = t;
	return 1;
}

void reset(int t){
	for(int i = 1 ; i <= r ; ++ i){
		for(int j = 1 ; j <= c ; ++ j){
			if(s[i][j] == t)s[i][j] = 0;
		}
	}
}

int dfs(int t){
	int cnt = 0;
	for(int i = 1 ; i <= r ; ++ i){
		for(int j = 1 ; j <= c ; ++ j){
			if(s[i][j] == 0)cnt ++;
		}
	}
	if(cnt == 0)return 0;
	for(int i = 1 ; i <= r ; ++ i){
		for(int j = 1 ; j <= c ; ++ j){
			if(s[i][j] != 0)continue;
			bool flag = check(i,j,0,t);
			if(flag){
				if(!dfs(t+1)){
					reset(t);
					return 1;
				}
			}
			reset(t);
			flag = check(i,j,1,t);
			if(flag){
				if(!dfs(t+1)){
					reset(t);
					return 1;
				}
			}
			reset(t);
		}
	}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q = 1 ; q <= T ; ++ q){
		scanf("%d%d",&r,&c);
		for(int i = 1 ; i <= r ; ++ i)scanf("%s",ss[i] + 1);
		for(int i = 1 ; i <= r ; ++ i){
			for(int j = 1 ; j <= c ; ++ j){
				if(ss[i][j] == '#')s[i][j] = -1;
				else s[i][j] = 0;
			}
		}
		printf("Case #%d: ",q);
		int ans = 0;
		for(int i = 1 ; i <= r ; ++ i){
			for(int j = 1 ; j <= c ; ++ j){
				if(s[i][j] != 0)continue;
				bool flag = check(i,j,0,1);
				if(flag){
					if(!dfs(2)){
						ans++;
					}
				}
				reset(1);
				flag = check(i,j,1,1);
				if(flag){
					if(!dfs(2)){
						ans++;
					}
				}
				reset(1);
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}
