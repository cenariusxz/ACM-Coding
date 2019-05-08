#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int a[15];

inline int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		ll ans=0;
		for(int i=1;i<(1<<n);++i){
			int bit=0;
			int mul=1;
			for(int j=1;j<=n;++j){
				if(i&(1<<(j-1))){
					bit++;
					mul=mul/gcd(mul,a[j])*a[j];
				}
			}
			if(bit%2)ans+=m/mul;
			else ans-=m/mul;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
