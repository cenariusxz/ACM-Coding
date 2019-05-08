#include<stdio.h>

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int a,b;
		if(n>m){
			a=m;
			b=m+n-a-1;
		}
		else{
			a=n;
			b=m+n-a-1;
		}
		printf("%d %d\n",b,a);
	}
	return 0;
}
