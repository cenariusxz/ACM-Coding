#include<stdio.h>
#include<string.h>

int main(){
	int n;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=n-2;
		if(ans<0)ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
