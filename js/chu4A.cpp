#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

ll num[5];
ll tim[5];
ll ta,tb;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i;
		ta=tb=0;
		for(i=1;i<=4;i++)scanf("%lld",&num[i]);
		for(i=1;i<=4;i++)scanf("%lld",&tim[i]);
		ta=num[1]*tim[1];
		tb=num[2]*tim[2];
		ll ans=0x7ffffffffffffff;
		for(i=0;i<=num[3];i++){
			ll t1=ta+i*tim[3];
			ll t2=tb+(num[3]-i)*tim[3];
			ll dif=(t1-t2>0)?t1-t2:t2-t1;
			double k=num[4]/2.0-dif*1.0/(2.0*tim[4]);
			ll kk=k;
			if(kk<0)kk=0;
			for(ll j=kk;j<=kk+2;j++){
				ll tmp1,tmp2;
				tmp1=t2+j*tim[4];
				tmp2=t1+(num[4]-j)*tim[4];
				if(max(tmp1,tmp2)<ans){
					ans=max(tmp1,tmp2);
				}
				tmp1=t1+j*tim[4];
				tmp2=t2+(num[4]-j)*tim[4];
				if(max(tmp1,tmp2)<ans){
					ans=max(tmp1,tmp2);
				}
				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
