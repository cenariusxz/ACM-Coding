#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n-n/(m+1)*(m+1))printf("first\n");
		else printf("second\n");
	}
}
