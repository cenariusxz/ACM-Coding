#include<stdio.h>

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		if((n-1)%2||(m-1)%2)printf("Wonderful!\n");
		else printf("What a pity!\n");
	}
	return 0;
}
