#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	printf("%d\n",20);
	srand(time(NULL));
	int n=20;
	for(int i=1;i<=n;++i){
		int a,b,k;
		a=rand()%10+1;
		b=rand()%10+1;
		k=rand()%11;
		printf("1 %d 1 %d %d\n",a,b,k);
	}
	return 0;
}
