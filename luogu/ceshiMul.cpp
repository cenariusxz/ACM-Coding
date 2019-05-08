#include <bits/stdc++.h>
using namespace std;

int a[1000];
char s[1000];

struct Num{
	int d[505];
	int len;
	Num(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};

Num mulNum(Num a,int x){
	Num ans;
	int len = a.len;
	for(int i = 0 ; i < len ; ++ i)ans.d[i] = a.d[i]*x;
	for(int i = 0 ; i < len ; ++ i){
		ans.d[i+1] += ans.d[i] / 10;
		ans.d[i] %= 10;
	}
	if(ans.d[len])len++;
	while(ans.d[len-1] >= 10){
		ans.d[len] = ans.d[len-1] / 10;
		ans.d[len-1] %= 10;
		len++;
	}
	ans.len = len;
	return ans;
}

int main(){
	memset(a,0,sizeof(a));
	int x;
	scanf("%d",&x);
	scanf("%s",s);
	int len = strlen(s);
	for(int i = 0 ; s[i] ; ++ i)a[len-i-1] = s[i]-'0';
	for(int i = 0 ; i < len ; ++ i)a[i] *= x;
	for(int i = 0 ; i < len ; ++ i){
		a[i+1] += a[i] / 10;
		a[i] %= 10;
	}
	if(a[len])len++;
	while(a[len-1] >= 10){
		a[len] = a[len-1] / 10;
		a[len-1] %= 10;
		len++;
	}
	for(int i = len-1 ;  i >= 0 ; --i)printf("%d",a[i]);
	printf("\n");
	return 0;
}
