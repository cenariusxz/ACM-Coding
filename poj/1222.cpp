#include <stdio.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int a[10][10];
int ans[10][10];
int xx[4] = {0,-1,0,0};
int yy[4] = {0,0,-1,1};
bool solve(){
	for(int x = 1 ; x <= 5 ; ++ x){
		for(int y = 1 ; y <= 6 ; ++ y){
			int sum = a[x][y];
			for(int i = 0 ; i < 4 ; ++ i){
				int dx = x + xx[i];
				int dy = y + yy[i];
				if(dx < 1 || dx > 5 || dy < 1 || dy > 6)continue;
				sum += ans[dx][dy];
			}
			if(sum & 1)ans[x+1][y] = 1;
			else ans[x+1][y] = 0;
		}
	}
	for(int y = 1 ; y <= 6 ; ++ y){
		if(ans[6][y])return 0;
	}
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t = 1 ; t <= T ; ++ t){
		for(int i = 1 ; i <= 5 ; ++ i){
			for(int j = 1 ; j <= 6 ; ++ j){
				scanf("%d",&a[i][j]);
			}
		}
		for(int state = 0 ; state < (1<<6) ; ++ state){
			for(int j = 1 ; j <= 6 ; ++ j){
				if(state & (1 << (j-1)))ans[1][j] = 1;
				else ans[1][j] = 0;
			}
			if(solve())break;
		}
		printf("PUZZLE #%d\n",t);
		for(int i = 1 ; i <= 5 ; ++ i){
			for(int j = 1 ; j <= 6 ; ++ j){
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
