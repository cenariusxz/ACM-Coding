#include <stdio.h>
#include <string.h>

typedef long long ll;

int a,b,c;
int s[100];
ll C[40][40];

ll Solve(int v){
	if(v < 0) return 0;
	c = 0;
	while(v){
		s[++c] = v & 1;
		v >>= 1;
	}
	ll res = 0;
	int cnt = 0;
	for(int i = c; i >= 1; --i){
		if(s[i] == 1){
			for(int j = 0; j < i; ++j){
				res += 1ll * (j + cnt) * C[i - 1][j];
			}
			cnt++;
		}
	}
	return res + cnt;
}

int main(){
	for(int i = 0; i < 40; ++i){
		for(int j = 0; j <= i; ++j){
			if(j == 0 || j == i) C[i][j] = 1;
			else{
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
	}
	int tt = 0;
	while(scanf("%d%d",&a,&b) != EOF){
		if(a == 0 && b == 0) break;
		printf("Case %d: %lld\n",++tt,Solve(b) - Solve(a - 1));
	}
	return 0;
}
