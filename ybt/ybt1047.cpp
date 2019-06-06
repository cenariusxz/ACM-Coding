#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int cnt = 0;
	scanf("%d",&n);
	if(n%3 == 0){
		printf("3");
		cnt ++;
	}
	if(n%5 == 0){
		if(cnt)printf(" ");
		printf("5");
		cnt ++;
	}
	if(n%7 == 0){
		if(cnt)printf(" ");
		printf("7");
		cnt ++;
	}
	if(!cnt)printf("n");
	printf("\n");
	return 0;
}
