#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

ll ansr,ansk;

ll QP(ll a,int n){
	ll ans=1,tmp=a;
	while(n){
		if(n&1)ans=ans*tmp;
		tmp=tmp*tmp;
		n>>=1;
	}
	return ans;
}

int main(){
	ll n;
	while(scanf("%lld",&n)!=EOF){
		ansr=1;
		ansk=n-1;
		for(int i=2;i<=40;++i){
			ll l=2,r=(ll)pow(n*1.0,1.0/i)+1;
			while(l<=r){
				ll mid=(l+r)>>1;
			//	ll num=(QP(mid,i+1)-mid)/(mid-1);
				ll num=0;
				ll tmp=mid;
				for(int j=1;j<=i;++j){
					num+=tmp;
					tmp=tmp*mid;
				}
				if(num==n||num==n-1){
					if(mid*i<ansr*ansk){
						ansr=i;
						ansk=mid;
					}
					else if(mid*i==ansr*ansk&&i<ansr){
						ansr=i;
						ansk=mid;
					}
					break;
				}
				else if(num<n-1)l=mid+1;
				else if(num>n)r=mid-1;
			}
		}
		printf("%lld %lld\n",ansr,ansk);
	}
	return 0;
}
