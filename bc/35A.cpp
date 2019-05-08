#include<stdio.h>
#include<string.h>

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int s=n*m;
		int sum=n+m;
		int g=gcd(s,sum);
		printf("%d/%d\n",s/g,sum/g);
	}
	return 0;
}
