#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

const int mod=1e9;

int main(){
	srand(time(NULL));
	printf("10\n");
	printf("5 2\n1 2 3 4 5\n1 5\n3 5\n4 1\n1 1 1 1\n1 2\n");
	for(int i=1;i<=7;++i){
		int n=rand()%100000+1,m=rand()%1000+1;
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;++i)printf("%d ",rand()%mod+1);
		printf("\n");
		for(int i=1;i<=m;++i){
			int a=rand()%n+1,b=rand()%n+1;
			if(a>b)swap(a,b);
			printf("%d %d\n",a,b);
		}
	}
	printf("100000 1000\n");
	for(int i=1;i<=100000;++i)printf("%d ",mod);
	printf("\n");
	for(int i=1;i<=1000;++i)printf("1 100000\n");
	return 0;
}
