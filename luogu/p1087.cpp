#include <bits/stdc++.h>
using namespace std;
#define MP make_pair

char s[2048];
int n;

void print(int B,int I){
	if(!I)printf("B");
	else if(!B)printf("I");
	else printf("F");
}

pair<int,int> dfs(int l,int r){
	int B=0,I=0;
	if(l == r){
		if(s[l] == '0')B++;
		else I++;
		print(B,I);
		return MP(B,I);
	}
	int m = (l+r) >> 1;
	pair<int,int> tmp;
	tmp = dfs(l,m);
	B += tmp.first;I += tmp.second;
	tmp = dfs(m+1,r);
	B += tmp.first;I += tmp.second;
	print(B,I);
	return MP(B,I);
}

int main(){
	while(scanf("%d%s",&n,s+1)!=EOF){
		dfs(1,1<<n);
		printf("\n");
	}
	return 0;
}
