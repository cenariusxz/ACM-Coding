#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int num=1e5;

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int x,k,c;
		ll m;
		scanf("%d%lld%d%d",&x,&m,&k,&c);
		ll ans=0;
		ll cnt=m/num;
		ll cnt2=m%num;
		ll num1=0,num2=1;
		for(int i=1;i<=num;++i){
			num1=(num1*10+x)%k;
		}
		for(int i=1;i<=num;++i){
			num2=num2*10%k;
		}
		for(int i=1;i<=cnt;++i){
			ans=(ans*num2+num1)%k;
		}
		for(int i=1;i<=cnt2;++i){
			ans=(ans*10+x)%k;
		}
		printf("Case #%d:\n",q);
		if(ans==c)printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
