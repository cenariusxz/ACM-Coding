#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;
int T;
char s[100010];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s + 1);
		int len = strlen(s + 1);
		int l = -1,r = -1;
		long long ans = 1;
		for(int i = 1; i <= len; ++i){
			if(s[i] == '?'){
				if(l == -1) l = i;
				r = i;
			}
			else{
				int res = 0;
				if(l - 1 > 0 && r + 1 <= len && s[l - 1] !=
						s[r + 1]){
					ans *= 1ll * (r - l + 2);
					ans %= mod;
				}
				l = r = -1;
			}
		}
		if(l != -1){
			if(l - 1 > 0 && r + 1 <= len && s[l - 1] != s[r + 1]){
				ans *= 1ll * (r - l + 2);
				ans %= mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
