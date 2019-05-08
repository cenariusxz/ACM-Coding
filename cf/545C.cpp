#include<stdio.h>
#include<string.h>
typedef long long ll;
ll x[100005],h[100005];

int main(){
	int n,i;
	scanf("%d",&n);
	if(n==1){
		for(i=1;i<=n;i++){
			scanf("%I64d%I64d",&x[i],&h[i]);
		}
		printf("1\n");
		return 0;
	}
	else{
		int ans=2;
		for(i=1;i<=n;i++){
			scanf("%I64d%I64d",&x[i],&h[i]);
		}
		ll pos=x[1];
		for(i=2;i<n;i++){
			if(x[i]-h[i]>pos){
				ans++;
				pos=x[i];
			}
			else if(x[i]+h[i]<x[i+1]){
				ans++;
				pos=x[i]+h[i];
			}
			else pos=x[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
