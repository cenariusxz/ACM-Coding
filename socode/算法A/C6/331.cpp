#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char s[10005];
int cnt[365];	// cnt[i]  i 这个数（字符）出现次数 

int main(){
	scanf("%s",s);
	int n = strlen(s);
	for(int i = 0 ; i < n ; ++ i){
		cnt[ s[i] ]++;
	}
	for(int i = 'a' ; i <= 'z' ; ++ i){
		printf("%d\n", cnt[i]);	
	}
	return 0;
}
