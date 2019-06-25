#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;

struct Num{
	int d[maxn];
	int len;
	Num(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};

Num mulNumEx(Num a,Num b){
	Num ans;
	int len = a.len+b.len-1;
	for(int i = 0 ; i < a.len ; ++ i){
		for(int j = 0 ; j < b.len ; ++ j){
			ans.d[i+j] += a.d[i] * b.d[j];
			if(ans.d[i+j] >= 10){
				ans.d[i+j+1] += ans.d[i+j]/10;
				ans.d[i+j] %= 10;
			}
		}
	}
	while(ans.d[len])++len;
	while(!ans.d[len-1] && len>1)--len;
	ans.len = len;
	return ans;
}

char s[maxn],t[maxn];

int main(){
	scanf("%s%s",s,t);
	int lens = strlen(s), lent = strlen(t);
	Num a,b;
	a.len = lens;
	for(int i = 0 ; i < lens ; ++ i){
		a.d[i] = s[lens-i-1] - '0';
	}
	b.len = lent;
	for(int i = 0 ; i < lent ; ++ i){
		b.d[i] = t[lent-i-1] - '0';
	}
	Num ans;
	ans = mulNumEx(a,b);

	for(int i = ans.len-1 ; i >= 0 ; -- i){
		printf("%d",ans.d[i]);
	}
	printf("\n");
	return 0;
}
