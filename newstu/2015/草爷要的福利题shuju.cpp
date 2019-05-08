#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	for(int i=1;i<=98;++i){
		int n=rand()%100+1;
		if(i==98)n=100;
		int a=rand()%20001;
		a-=10000;
		int b=rand()%20001;
		b-=10000;
		printf("%d %d %d\n",n,a,b);
		if(a>10000||a<-10000||b>10000||b<-10000)printf("AAAAA\n");
		for(int j=1;j<=n;++j){
			int x=rand()%20001;
			x-=10000;
			int y=rand()%20001;
			y-=10000;
			printf("%d %d\n",x,y);
			if(x>10000||x<-10000||y>10000||y<-10000)printf("AAAAA\n");
		}
	}
	return 0;
}
