#include <bits/stdc++.h>
using namespace std;

char s[105];
char a[105],b[105];

int main(){
	int T;
	scanf("%d",&T);
	for(int q = 1 ; q <= T ; ++ q){
		scanf("%s",s);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i = 0 ; s[i] ; ++ i){
			if(s[i] == '4'){
				a[i] = '1';
				b[i] = '3';
			}
			else{
				a[i] = s[i];
				b[i] = '0';
			}
		}
		printf("Case #%d: ",q);
		bool flag = 0;
		for(int i = 0 ; s[i] ; ++ i){
			if(!flag && a[i] == '0')continue;
			putchar(a[i]);
			flag = 1;
		}
		printf(" ");
		flag = 0;
		for(int i = 0 ; s[i] ; ++ i){
			if(!flag && b[i] == '0')continue;
			putchar(b[i]);
			flag = 1;
		}
		printf("\n");
	}
	return 0;
}
