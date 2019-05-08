#include<stdio.h>
#include<string.h>
#include<math.h>

int a[35];

int main(){
	int T;
	a[1]=1;
	for(int i=2;i<=30;++i){
		a[i]=2*a[i-1]+1;
	}
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
