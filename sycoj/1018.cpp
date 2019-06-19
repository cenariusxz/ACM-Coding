#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 50;
const int maxm = 1e6 + 6;

int n;
int a[maxn][maxn];

int main(){
	scanf("%d",&n);
	int x, y;
	for(int i = 1 ; i <= n*n ; ++ i){
		if(i == 1){
			a[x = 1][y = n/2+1] = i;
		}
		else if(x == 1 && y != n){
			a[x = n][++ y] = i;	
		}
		else if(x != 1 && y == n){
			a[-- x][y = 1] = i;	
		}
		else if(x == 1 && y == n){
			a[++ x][y] = i;	
		}
		else if(x != 1 && y != n){
			if(!a[x-1][y+1]){
				a[-- x][++ y] = i;
			}
			else{
				a[++ x][y] = i;	
			}
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			printf("%d",a[i][j]);
			if(j == n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}


