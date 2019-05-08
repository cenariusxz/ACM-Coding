#include<stdio.h>
#include<string.h>
#define ll long long

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			printf("%d %lld\n",i,ans);
		}
	}
	return 0;
}
