#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4 + 7;
const int maxn = 1e5 + 5;

int num[maxn],col[maxn];
int m,n,ans = 0;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&col[i]);
	for(int x = 1 ; x <= n ; ++ x){
		for(int y = x+1 ; y <= n ; ++ y){
			for(int z = y+1 ; z <= n ; ++ z){
				if(y - x == z - y && col[x] == col[z]){
					ans += (x+z)%mod * ((num[x]+num[z])%mod)%mod;
					ans %= mod;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
