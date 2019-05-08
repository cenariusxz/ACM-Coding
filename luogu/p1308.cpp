#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;

char s[maxn],t[15];
int stx,sum;
int lent,lens;

void check(int l){
	for(int i = 0 ; t[i] ; ++i){
		if(t[i] != s[l+i])return;
	}
	if(stx == -1)stx = l;
	sum++;
}

int main(){
	stx = -1,sum = 0;
	scanf("%s",t);
	gets(s);
	gets(s);
	lent = strlen(t);
	lens = strlen(s);
	t[lent] = ' ';t[lent+1] = 0;lent++;
	s[lens] = ' ';s[lens+1] = 0;lens++;
	for(int i = 0 ; t[i] ; ++ i){
		if(t[i] >= 'A' && t[i] <= 'Z')t[i] = t[i]-'A'+'a';
	}
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] >= 'A' && s[i] <= 'Z')s[i] = s[i]-'A'+'a';
	}
	check(0);
	for(int i = 1 ; s[i] ; ++ i){
		if(s[i] == t[0] && s[i-1] == ' ')check(i);
	}
	if(sum == 0)printf("-1\n");
	else printf("%d %d\n",sum,stx);
	return 0;
}
