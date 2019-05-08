#include<stdio.h>
typedef long long ll;
const int mod=1000033;

int ans[83337],T;
ll k;

int main(){
	int mul=10000,sub=33;
	ans[1]=9967;
	for(int i=2;i<=83336;++i)ans[i]=((ans[i-1]-33)*(ll)mul%mod+mod)%mod;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&k);
		printf("%d\r\n",ans[k%83336+(k%83336?0:83336)]);
	}
	return 0;
}
