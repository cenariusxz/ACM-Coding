#include <stdio.h>

typedef long long ll;

int n;
int m;
int S[100];
int cnt;

void Convert(ll v){
	cnt = 0;
	while(v){
		S[++cnt] = v % m;
		v /= m;
	}
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		ll ans = 0;
		for(int i = 1; i * i <= n; ++i) if(n % i == 0){
			Convert(i);
			for(int j = 1; j <= cnt; ++j){
				ans += S[j] * S[j];
			}
			if(n / i != i){
				Convert(n / i);
				for(int j = 1; j <= cnt; ++j){
					ans += S[j] * S[j];
				}
			}
		}
		Convert(ans);
		for(int i = cnt; i >= 1; --i){
			if(S[i] >= 10) printf("%c",'A' + S[i] - 10);
			else printf("%d",S[i]);
		}
		puts("");
	}
	return 0;
}
