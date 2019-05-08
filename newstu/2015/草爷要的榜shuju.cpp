#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	for(int i=1;i<=97;++i){
		int n=rand()%100+1;
		int k=rand()%10+1;
		printf("%d %d\n",n,k);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k;++j){
				printf("0%d:",rand()%5);
				int a=rand()%60;
				if(a<=9)printf("0%d",a);
				else printf("%d",a);
				if(j==k)printf("\n");
				else printf(" ");
			}
			for(int j=1;j<=k;++j){
				printf("%d",rand()%100+1);
				if(j==k)printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
