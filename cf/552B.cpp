#include<stdio.h>
#include<string.h>
typedef long long ll;

ll a[11]={0,9l,180l,2700l,36000l,450000l,5400000l,63000000l,720000000l,8100000000,10l};

int main(){
	int n;
	
	scanf("%d",&n);
	ll ans=0,cnt=0;
	int nn=n;
	ll m=1;
	while(nn/10){
		nn/=10;
		cnt++;
		m*=10;
		ans+=a[cnt];
	}
//	printf("%lld\n",m);
/*	ll tmp=0;
	for(int i=1;i<=10;i++){
		tmp+=a[i];
	}
	printf("%lld\n",tmp);
*/	ans+=(n-m+1)*(cnt+1);
	printf("%I64d\n",ans);
	return 0;
}
