#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int f(int x,int y){
	int c=0;
	while(y){
		++c;
		int t=x%y;
		x=y;
		y=t;
	}
	return c;
}

int main(){
	int m=3;
	int sum=0;
	for(int i=1;i<=m;++i)printf("%d\n",f(i,m));
	for(int i=1;i<=20;++i){
		int num=(i*m)/(f(i,m));
		sum+=num;
		printf("%d : %d\n",i,num);
	}
	//	for(int i=1;i<=100;++i){
//		if(__gcd(i,m)==1)printf("%d\n",i);
//	}
	return 0;
}
