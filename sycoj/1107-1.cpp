#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
const int mod = 1e4;

char s[maxn];

int solve(int l,int r){
	bool addflag = 0;
	bool mulflag = 0;
	for(int i = l ; i <= r ; ++ i){
		if(s[i] == '+')addflag = 1;
		if(s[i] == '*')mulflag = 1;
	}
	if(addflag){
		int pre = l-1, ans = 0;
		for(int i = l ; i <= r ; ++ i){
			if(s[i] == '+'){
				ans = (ans + solve(pre+1,i-1)) % mod;
				pre = i;
			}
		}
		ans = (ans + solve(pre+1,r)) % mod;
		return ans;
	}
	else if(mulflag){
		int pre = l-1, ans = 1;
		for(int i = l ; i <= r ; ++ i){
			if(s[i] == '*'){
				ans = ans * solve(pre+1,i-1) % mod;
				pre = i;
			}
		}
		ans = ans * solve(pre+1,r) % mod;
		return ans;
	}
	else{
		int ans = 0;
		for(int i = l ; i <= r ; ++ i){
			ans = ans * 10 + s[i] - '0';
			ans %= mod;
		}
		return ans;
	}
}

int main(){
	scanf("%s",s+1);
	int len = strlen(s+1);
	printf("%d\n",solve(1,len));
	return 0;
}
