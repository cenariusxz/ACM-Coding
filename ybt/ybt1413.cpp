#include <bits/stdc++.h>
using namespace std;
char p[30],q[30],r[30];

int tran(char s[],int b){
	int res=0;
	for(int i = 0 ; s[i] ; ++ i){
		res = res*b + s[i] - '0';
	}
	return res;
}

bool check(int b){
	int P=tran(p,b);
	int Q=tran(q,b);
	int R=tran(r,b);
	if(P*Q==R) return 1;
	return 0;
}

int main(){
	int i;
	scanf("%s%s%s",p,q,r);
	int Max = 0;
	for(int i = 0 ; p[i] ; ++ i)Max = max(Max,p[i]-'0');
	for(int i = 0 ; q[i] ; ++ i)Max = max(Max,q[i]-'0');
	for(int i = 0 ; r[i] ; ++ i)Max = max(Max,r[i]-'0');
	for(i=Max+1 ; i<=40 ; ++ i){
		if(check(i)){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
