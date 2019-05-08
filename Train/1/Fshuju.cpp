#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	int t=50;
	printf("%d\n",t);
	srand(time(NULL));
	for(int i=1;i<=t;++i){
		int n=20,w=650;
		printf("%d %d\n",n,w);
		for(int j=1;j<=n;++j)printf("%d ",rand()%100+500);
		printf("\n");
	}

}
