#include <bits/stdc++.h>
using namespace std;

struct Num{
	int d[505];
	int len;
	Num(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};

Num addNum(Num a, Num b){
	Num ans;
	int len = max(a.len, b.len);
	for(int i = 0 ; i < len ; ++ i){
		ans.d[i] += a.d[i] + b.d[i];
		ans.d[i+1] += ans.d[i] / 10;
		ans.d[i] %= 10;
	}
	ans.len = len;
	if(ans.d[len])ans.len++;
	return ans;
}

char s[505],t[505];

int main(){
	scanf("%s%s",s,t);
	int lens = strlen(s),lent = strlen(t);
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
	ans = addNum(a,b);

	for(int i = ans.len-1 ; i >= 0 ; -- i)printf("%d",ans.d[i]);
	printf("\n");
	return 0;
}
