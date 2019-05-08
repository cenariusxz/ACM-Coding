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

Num addNum(Num a, Num b, int n){
	Num ans;
	int len = max(a.len, b.len);
	for(int i = 0 ; i < len ; ++ i){
		ans.d[i] += a.d[i] + b.d[i];
		ans.d[i+1] += ans.d[i] / n;
		ans.d[i] %= n;
	}
	ans.len = len;
	if(ans.d[len])ans.len++;
	return ans;
}

Num reNum(Num a){
	Num ans;
	ans.len = a.len;
	for(int i = 0 ; i < a.len ; ++ i){
		ans.d[i] = a.d[a.len - i - 1];
	}
	for(int i = ans.len-1 ; i >= 0 ; -- i){
		if(ans.d[i])break;
		ans.len--;
	}
	return ans;
}

bool check(Num a){
	int len = a.len;
	for(int i = 0 , j = len - 1; i < j ; i++,j-- ){
		if(a.d[i] != a.d[j])return 0;
	}
	return 1;
}

int n;
char s[505];

int main(){
	while(scanf("%d%s",&n,s)!=EOF){
		int lens = strlen(s);
		Num a;
		a.len = lens;
		for(int i = 0 ; i < lens ; ++ i){
			if(s[lens-i-1]>='0' && s[lens-i-1]<='9')a.d[i] = s[lens-i-1] - '0';
			else a.d[i] = s[lens-i-1] - 'A' + 10;
		}
		Num x = reNum(a);
		int step;
		for(step = 1 ; step <= 30 ; ++ step){
			Num b = reNum(a);
			a = addNum(a,b,n);
			if(check(a))break;
		}
		if(step == 31)printf("Impossible!\n");
		else printf("STEP=%d\n",step);
	}
	return 0;
}
