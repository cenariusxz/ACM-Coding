#include <stdio.h>
#include <string.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

ll C[30][30];
char s[maxn];

void init(){
	for(int i = 0 ; i <= 26 ; ++ i){
		for(int j = 0 ; j <= i ; ++ j){
			C[i][j] = (j==0||j==i)?1:C[i-1][j-1]+C[i-1][j];
			// if(C[i][j] < 0)printf("???\n");
		}
	}
}

ll getC(int n,int m){
	if(m > n)return 0;
	return C[n][m];	
}

int main(){
	init();
	scanf("%s",s+1);
	for(int i = 2 ; s[i] ; ++ i){
		if(s[i] < s[i-1]){
			printf("0\n");
			return 0;
		}
	}
	int n = strlen(s+1);
	ll ans = 0;
	for(int i = 1 ; i < n ; ++ i)ans += getC(26, i);
	s[0] = 'a'-1;
	for(int i = 1 ; i <= n ; ++ i){
		// s[i-1] ~ s[i]  i+1~n
		for(int j = s[i-1] + 1 ; j < s[i] ; ++ j){
			// j+1 ~ 'z'  ->  i+1 ~ n
			ans += getC('z' - (j+1) + 1, n - (i+1) + 1);
		}
	}
	printf("%lld\n",ans+1);
	return 0;
}

