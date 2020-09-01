#include <bits/stdc++.h>
using namespace std;

int n;
int a[505][505], visr[505], visc[505], sumr[505], sumc[505];

void solve(){
	for(int t = 1 ; t <= n ; ++ t){
		memset(sumr, 0, sizeof(sumr));
		memset(sumc, 0, sizeof(sumc));
		for(int i = 1 ; i <= n ; ++ i){
			if(visr[i])continue;
			for(int j = 1 ; j <= n ; ++ j){
				if(visc[j])continue;
				sumr[i] += a[i][j];
				sumc[j] += a[i][j];
			}
		}
		int ansr = 0, ansc = 0, r = 0, c = 0, nowr = 0, nowc = 0, ans = -1;
		for(int i = 1 ; i <= n ; ++ i){
			if(visr[i])continue;
			++ nowr;
			nowc = 0;
			for(int j = 1 ; j <= n ; ++ j){
				if(visc[j])continue;
				++ nowc;
				int tmp = sumr[i] + sumc[j] - a[i][j];
				if(tmp > ans)ans = tmp, ansr = nowr, ansc = nowc, r = i, c = j;
			}
		}
		visr[r] = visc[c] = 1;
		printf("%d %d\n", ansr, ansc);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j)scanf("%d", &a[i][j]);	
	}
	solve();
	return 0;
}

