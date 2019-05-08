#include <bits/stdc++.h>
using namespace std;

int bit[20];

void init(){
	bit[0] = 1;
	for(int i = 1 ; i <= 15 ; ++ i)bit[i] = bit[i-1] * 2;
}

void solve(int a){
	int cnt = 0;
	for(int i = 15 ; i >= 0 ; -- i){
		if(a >= bit[i]){
			if(cnt)printf("+");
			cnt++;
			if(i == 0)printf("2(0)");
			else if(i == 1)printf("2");
			else{
				printf("2(");
				solve(i);
				printf(")");
			}
			a-=bit[i];
		}
	}
}

int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		solve(n);
		printf("\n");
	}
	return 0;
}
