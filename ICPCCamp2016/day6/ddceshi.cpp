#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main(){
	srand(time(NULL));
	for(int t=1;t<=10;++t){
		int n=8;
		printf("8\n");
		for(int i=1;i<=n;++i){
			printf("%d ",rand()%10+1);
		}
		printf("\n");
		for(int i=1;i<=n;++i){
			printf("%d ",rand()%10+1);
		}
		printf("\n");
	}
	return 0;
}
