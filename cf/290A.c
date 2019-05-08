#include<stdio.h>
#include<string.h>

int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		if(i%2){
			for(j=1;j<=m;j++){
				printf("#");
			}
		}
		else if((i/2)%2){
			for(j=1;j<m;j++)printf(".");
			printf("#");
		}
		else{
			printf("#");
			for(j=1;j<m;j++)printf(".");
		}
		printf("\n");
	}
}
