#include <bits/stdc++.h>
using namespace std;

char s[105];

int main(){
	scanf("%s",s);
	int pre = 'a';
	int ans = 0;
	for(int i = 0 ; s[i] ; ++ i){
		int now = s[i];
		if(now > pre)ans += min(now - pre, pre + 26 - now);
		else ans += min(pre - now, now + 26 - pre);
		pre = now;
	}
	printf("%d\n",ans);
	return 0;
}
