#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("1\n1\n");
	}
	else if(n==2){
		printf("1\n1\n");
	}
	else if(n==3){
		printf("2\n1 3\n");
	}
	else if(n==4){
		printf("4\n3 1 4 2\n");
	}
	else{
		printf("%d\n",n);
		int i,x1,x2;
		if(n%2){
			x1=n;x2=n-1;
		}
		else{
			x1=n-1;x2=n;
		}
		for(i=x1;i>=1;i-=2){
			printf("%d ",i);
		}
		for(i=x2;i>=2;i-=2){
			printf("%d",i);
			if(i==2)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
