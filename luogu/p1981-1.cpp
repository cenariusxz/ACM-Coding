#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
const int mod = 1e4;

char s[maxn];

int main(){
	scanf("%s",s+1);
	int len = strlen(s+1);
	s[len+1] = '+';
	int ans = 0, mul = 1, num = 0;
	for(int i = 1 ; s[i] ; ++ i){
		if(s[i] >= '0' && s[i] <= '9')num = (num * 10 + s[i] - '0') % mod;
		else if(s[i] == '*'){
			mul = mul * num % mod;
			num = 0;
		}
		else{
			mul = mul * num % mod;
			num = 0;
			ans = (ans + mul) % mod;
			mul = 1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
