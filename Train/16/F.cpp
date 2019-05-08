#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int n,Exp;
char g[1100][1100];
int ts[1100],s[1100];
int ans[2][1100],acnt;

bool Check(){
	acnt = 0;
	int cur = n;
	for(int i = 1; i <= cur; ++i) ts[i] = s[i];
	for(int o = 1; o <= Exp; ++o){
		int nxt = 0;
		for(int i = 1; i <= cur; i += 2){
			ans[0][++acnt] = ts[i];
			ans[1][acnt] = ts[i + 1];
			if(g[ts[i]][ts[i + 1]] == '1'){
				ts[++nxt] = ts[i];
			}
			else{
				ts[++nxt] = ts[i + 1];
			}
		}
		cur = nxt;
		bool f = false;
		for(int i = 1; i <= cur; ++i) if(ts[i] == 1) f = true;
		if(!f) return false;
	}
	return ts[1] == 1;
}

int main(){
	while(scanf("%d",&n) != EOF){
		int tn = n;
		Exp = -1;
		while(tn){
			tn /= 2;
			Exp++;
		}
		for(int i = 1; i <= n; ++i){
			scanf("%s",g[i] + 1);
		}
		for(int i = 1; i <= n; ++i) s[i] = i;
		while(!Check()){
			random_shuffle(s + 1,s + n + 1);
		}
		//for(int i = 1; i <= n; ++i) printf("%d ",s[i]);
		//puts("");
		for(int i = 1; i <= acnt; ++i){
			printf("%d %d\n",ans[0][i],ans[1][i]);
		}
	}
	return 0;
}
