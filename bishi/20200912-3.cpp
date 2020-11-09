#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

char s[maxn], q[10] = "abcxyz";
int cnt[26][maxn];

int main(){
	scanf("%s", s+1);
	int n = strlen(s + 1);
	for(int i = 1 ; s[i] ; ++ i){
		for(int j = 0 ; j < 26 ; ++ j)cnt[j][i] = cnt[j][i-1];
		cnt[s[i]-'a'][i] ++;
	}
	for(int len = n ; len >= 1 ; -- len){
		for(int l = 1 ; l + len - 1 <= n ; ++ l){
			int r = l + len - 1;
			bool flag = 1;
			for(int i = 0 ; i < 6 ; ++ i){
				if( (cnt[q[i]-'a'][r] - cnt[q[i]-'a'][l-1]) & 1)flag = 0;
			}
			if(flag){
				printf("%d\n", len);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}

