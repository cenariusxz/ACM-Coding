#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int n = 0, a[maxn], ans;
string ss;

bool precheck(){
	int len = ss.length();
	int cnt = 0;
	for(int i = 0 ; i < len ; ++ i){
		if((ss[i] < '0' || ss[i] > '9') && ss[i] != ' ' && ss[i] != '-')return 0;
		 if(ss[i] == ' ')++ cnt;
		 else cnt = 0;
		 if(cnt > 1)return 0;
	}
	return 1;
}

bool readnum(){
	ss = ss + "+";
	int len = ss.length(), flag = 0, nflag = 1;
	for(int i = 0 ; i < len ; ++ i){
		if(ss[i] == '-' || (ss[i] >= '0' && ss[i] <= '9')){
			if(flag == 0)++ n;
			if(n > 100000)return 0;	// this
			if(ss[i] == '-'){
				if(flag)return 0;
				nflag = -1;
			}
			else a[n] = a[n] * 10 + ss[i] - '0';
			if(a[n] > 100000 || (a[n] && nflag == -1))return 0;
			flag = 1;
		}
		else flag = 0, nflag = 1;
	}
	return 1;
}

int main(){
	getline(cin, ss);
	int len = ss.length();
	for(int i = 0 ; i < len ; ++ i){
		if(ss[i] == '+')while(1){
			
		}
	}
	if(!precheck()){
		printf("-1\n");
		return 0;
	}
	if(!readnum()){
		printf("-1\n");
		return 0;
	}
	//for(int i = 1 ; i <= n ; ++ i)printf("%d ", a[i]);
	//printf("\n");
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(a[i] > a[i-1])ans += a[i] - a[i-1];
	}
	printf("%lld\n", ans);
	return 0;
}

