#include <stdio.h>

int T,x;

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){	
		scanf("%d",&x);
		printf("Case #%d:\n",tt);
		x /= 10;
		printf("*------------*\n");
		int num = 10 - x;
		for(int i = 1; i <= num; ++i){
			printf("|............|\n");
		}
		for(int i = 1; i <= x; ++i){
			printf("|------------|\n");
		}
		printf("*------------*\n");
	}
	return 0;
}
