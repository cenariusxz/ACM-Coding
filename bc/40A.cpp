#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int n;
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
		int a,b,i;
		a=sqrt(n*1.0)+1;
		for(i=a;i>=1;i--){
			if(!(n%i)){
				a=i;
				b=n/i;
				break;
			}
		}
		printf("%d\n",a+b+a+b);
	}
	return 0;
}
