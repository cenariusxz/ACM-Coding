#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;

ll dp[maxn][maxn];
int vis[maxn][maxn];
int xx[9] = {0,-2,-2,-1,-1,1,1,2,2};
int yy[9] = {0,1,-1,2,-2,2,-2,1,-1};

int main(){
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	n++;m++;a++;b++;
	memset(num,0,sizeof(num));
	memset(vis,0,sizeof(vis));
	for(int i = 0 ; i < 9 ; ++ i){
		int x = a + xx[i], y = b + yy[i];
		if(x < 1 || x > n || y < 1 || y > n)continue;
		vis[x][y] = 1;
	}
	//		if(vis[1][1]){
	//			printf("0\n");
	//			return 0;
	//		}
	num[1][1] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if( (i == 1 && j == 1) || vis[i][j] )continue;
			num[i][j] = num[i-1][j] + num[i][j-1];
		}
	}
	printf("%lld\n",num[n][m]);
	return 0;
}
