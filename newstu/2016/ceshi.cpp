#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1000033;

int ans[83337],T;
ll k;

int main(){
	int mul=10000,add=33;
	ans[1]=10033;
	for(int i=2;i<=83336;++i)ans[i]=(ans[i-1]+33)*(ll)mul%mod;
	ll num=10033;
	for(int i=1;i<=20000000;++i){
		int tmp1=ans[i%83336+(i%83336?0:83336)];
		if(tmp1!=num)printf("WA\n");
		num=(num+add)*mul%mod;
	}
	return 0;
}
