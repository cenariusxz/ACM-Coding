#include <bits/stdc++.h>
using namespace std;

char s[15],t[15];

void dfs(int l1,int r1,int l2,int r2){
	if(l1 > r1)return;
	char root = t[r2];
	printf("%c",root);
	for(int i = l1 ; i <= r1 ; ++ i){
		if(s[i] == root){
//		[l1   i-1]   i  [i+1  r1]
//		[l2  l2+len1-1]  [l2+len1 r2-1]  r2
			int len1 = (i-1) - l1 + 1;
			int len2 = r1 - (i+1) + 1;
			dfs(l1,i-1,l2,l2+len1-1);
			dfs(i+1,r1,l2+len1,r2-1);
			break;
		}
	}
}

int main(){
	while(scanf("%s%s",s,t)!=EOF){
		int len = strlen(s);
		dfs(0,len-1,0,len-1);
		printf("\n");
	}
	return 0;
}
