#include<stdio.h>

int main(){
	freopen("out.txt","w",stdout);
	printf("10000\n");
	for(int i=1;i<=10000;i++){
		printf("%d ",i);
	}
	printf("\n");
	return 0;
}
