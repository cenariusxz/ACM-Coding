#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e2 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int a[maxn][maxn],b[maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%d",&a[i][j]);
		}
	}
	int ans = 0;
	for(int len = 1 ; len <= n && ans == len - 1 ; ++ len){
		for(int up = 1 ; up + len - 1 <= n && ans == len - 1 ; ++ up){
			int down = up + len - 1;
			int sum = 0;
			for(int i = 1 ; i <= m && ans == len - 1 ; ++ i){
				b[i] = 1;
				for(int j = up ; j <= down ; ++ j){
					if(a[j][i] == 0)b[i] = 0;	
				}
				if(b[i])sum ++;
				else sum = 0;
				if(sum >= len)ans = len;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

