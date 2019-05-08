#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int num[200000];

int main(){
	srand(time(NULL));
	int t=20;
	printf("%d\n",t);
	while(t--){
		int n=90000+rand()%10000;
		int q=900+rand()%100;
		printf("%d %d\n",n,q);
		for(int i=1;i<=n;++i)num[i]=i%10;
		random_shuffle(num+1,num+n);
		for(int i=1;i<=n;++i){
			printf("%d",num[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
		while(q--){
			if(rand()%5<=2){
				int type=1;
				int x=rand()%10,y=rand()%10,a=9000+rand()%1000;
				printf("%d %d %d %d\n",type,x,y,a);
			}
			else{
				int type=2;
				int a,b;
				a=rand()%1000+1;
				b=a+rand()%(n-a);
				printf("%d %d %d\n",type,a,b);
			}
		}
	}
}
