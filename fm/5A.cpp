#include<stdio.h>
#include<string.h>
#include<algorithm>
//#include<math.h>
using namespace std;
typedef long long ll;

ll a[20];

int main(){
	ll n;
	int m;
	while(scanf("%lld%d",&n,&m)!=EOF){
		for(int i=1;i<=m;++i){
			scanf("%lld",&a[i]);
			if(a[i]<=0)printf("aaa\n");
		}
		ll ans=0;
		for(int i=1;i<(1<<(m));++i){
			int bit=0;
			ll tmp=1;
			for(int j=1;j<=m;++j){
				if(i&(1<<(j-1))){
					bit++;
					if(a[j]>0)tmp=tmp/__gcd(tmp,a[j])*a[j];
				}
			}
			if(bit%2)ans+=n/tmp;
			else ans-=n/tmp;
		}
		printf("%lld\n",n-ans);
	}
	return 0;
}
