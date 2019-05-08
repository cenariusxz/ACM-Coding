#include<stdio.h>

int main(){
	printf("1\n");
	printf("50 1225 1000000000 125000\n");
	int n=50;
	for(int i=1;i<=50;++i){
		printf("1");
		if(i==50)printf("\n");
		else printf(" ");
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			printf("%d %d\n",i,j);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				printf("%d %d %d\n",i,j,k);
			}
		}
	}
}
