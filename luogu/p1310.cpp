#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int mod = 1e4+7;

int n;
char s[maxn];
int presum[maxn],match[maxn];
int bit[maxn];

void init(){
	bit[0] = 1;
	for(int i = 1 ; i <= 100001 ; ++ i)bit[i] = bit[i-1] * 2 % mod;
}

int solve(int l,int r,int target){
	if(l>r)return 1;
	if(s[l] == '(' && match[l] == r)return solve(l+1,r-1,target);
	bool addflag = 0;
	bool mulflag = 0;
	int ans = 1;
	for(int i = l ; i <= r ; ++ i){
		if(s[i] == '(')i = match[i];
		if(s[i] == '+')addflag = 1;
		if(s[i] == '*')mulflag = 1;
	}
	if(addflag){
		int pre = l-1;
		for(int i = l ; i <= r ; ++ i){
			if(s[i] == '(')i = match[i];
			if(s[i] == '+'){
				ans = ans * solve(pre+1,i-1,0) % mod;
				pre = i;
			}
		}
		ans = ans * solve(pre+1,r,0) % mod;
		if(target == 0)return ans;
		int op = presum[r] - presum[l-1] + 1;
		ans = ((bit[op] - ans) % mod + mod ) % mod;
		return ans;
	}
	else if(mulflag){
		int pre = l-1;
		for(int i = l ; i <= r ; ++ i){
			if(s[i] == '(')i = match[i];
			if(s[i] == '*'){
				ans = ans * solve(pre+1,i-1,1) % mod;
				pre = i;
			}
		}
		ans = ans * solve(pre+1,r,1) % mod;
		if(target == 1)return ans;
		int op = presum[r] - presum[l-1] + 1;
		ans = ((bit[op] - ans) % mod + mod ) % mod;
		return ans;
	}
}

int main(){
	init();
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i = 1 ; s[i] ; ++ i){
		presum[i] = presum[i-1];
		if(s[i] == '+'||s[i] == '*')presum[i]++;
	}
	stack<int>S;
	for(int i = 1 ; s[i] ; ++ i){
		if(s[i] == '(')S.push(i);
		if(s[i] == ')'){
			int u = S.top();S.pop();
			match[u] = i;
		}
	}
	printf("%d\n",solve(1,n,0));
	return 0;
}
