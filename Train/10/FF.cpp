#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

int s[100];
int n;
double ans;

void Solve(){
	int tmax = 0,t[2] = {0};
	for(int i = 1; i <= n; ++i){
		if(s[i] == -1){
			t[0]++;
			t[1]--;
			if(t[1] < 0) t[1] = 0;
		}
		else{
			t[0]--;
			t[1]++;
			if(t[0] < 0) t[0] = 0;
		}
		tmax = max(tmax,max(t[0],t[1]));
	}
	ans += tmax;
}

void Dfs(int p){
	if(p > n){
		Solve();
		return;
	}
	s[p] = 1;
	Dfs(p + 1);
	s[p] = -1;
	Dfs(p + 1);
}

int main(){
	for(n = 1; n <= 10; ++n){
		ans = 0;
		Dfs(1);
		for(int i = 1; i <= n; ++i)
			ans /= 2.0;
		printf("%d : %.12f\n",n,ans);
	}
	return 0;
}

