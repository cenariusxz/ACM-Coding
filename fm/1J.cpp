#include<stdio.h>
#include<string.h>

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		while(n){
			n/=2;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
