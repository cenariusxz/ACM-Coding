#include <bits/stdc++.h>
using namespace std;

char num[50];
int S,T,w;
char s,t;

void solve(){
	for(int i = w ; i >= 1 ; -- i){
		if(num[i] == t - w + i)continue;
		num[i] ++;
		for(int j = i+1 ; j <= w ; ++ j){
			num[j] = num[i] + j-i;
		}
		printf("%s\n",num+1);
		return;
	}
}

int main(){
	scanf("%d%d%d",&S,&T,&w);
	scanf("%s",num+1);
	s = 'a' + S - 1;
	t = 'a' + T - 1;
	for(int i = 1 ; i <= 5 ; ++ i)solve();
	return 0;
}	

