#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4 + 7;
const int maxn = 1e5 + 5;

int col[maxn],number[maxn];
int id[maxn][21],num[maxn][21],cnt[maxn];
int n,m,ans = 0;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&number[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&col[i]);
	if(n <= 3000){
		for(int x = 1 ; x <= n ; ++ x){
			for(int z = x+2; z <= n ; z += 2){
				if(col[x] == col[z]){
					ans += (x+z)%mod * ((number[x]+number[z])%mod)%mod;
					ans %= mod;
				}
			}
		}
	}
	else{
		for(int i = 1 ; i <= n ; ++ i){
			cnt[col[i]]++;
			id[col[i]][cnt[col[i]]] = i; 
			num[col[i]][cnt[col[i]]] = number[i];
		}
		for(int i = 1 ; i <= m ; ++ i){
			for(int idx = 1 ; idx <= cnt[i] ; ++ idx){
				for(int idz = idx+1 ; idz <= cnt[i] ; ++ idz){
					int x = id[i][idx],z = id[i][idz];
					int nx = num[i][idx],nz = num[i][idz];
					if((x + z)%2 == 0){
						ans += (x+z)%mod * ((nx+nz)%mod)%mod;
						ans %= mod;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
