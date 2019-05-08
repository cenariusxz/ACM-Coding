#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",2*n);
	for(int i=1;i<=n;++i){
		printf("%d %d\n",i,i+n);
		for(int j=1;j<n;++j)printf("%d %d\n",i+n,i+j);
		for(int j=1;j<n;++j){
			int t=(n+i+j)%(2*n);
			if(t==0)t=2*n;
			printf("%d %d\n",i,t);
		}
	}
	return 0;
}
