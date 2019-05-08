#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int pnum=36;
const double eps=1e-8;

int num[40]={0,
	2,3,5,6,7,
	10,11,13,14,15,
	17,19,21,22,23,
	26,29,30,31,33,
	34,35,37,38,39,
	41,42,43,46,47,
	51,53,55,57,58,
	59};
int bit[40]={0,
	1,1,1,2,1,
	2,1,1,2,2,
	1,1,2,2,1,
	2,1,3,1,2,
	2,2,1,2,2,
	1,3,1,2,1,
	2,1,2,2,2,
	1};
int high[40]={0,
	1000000000,1000000,3981,1000,372,
	63,43,24,19,15,
	13,8,7,6,6,
	4,4,3,3,3,
	3,3,3,2,2,
	2,2,2,2,2,
	2,2,2,2,2,
	2};

ll n;

ll QP(ll a,int i){
	ll ans=1,tmp=a;
	while(i){
		if(i&1)ans*=tmp;
		tmp*=tmp;
		i>>=1;
	}
	return ans;
}

int check(int i){
	int l=1,r=high[i];
	while(l<=r){
		int m=l+((r-l)>>1);
		ll res=QP(m,num[i]);
		if(res<=n)l=m+1;
		else r=m-1;
	}
	return r-1;
}

int main(){
	while(scanf("%lld",&n)!=EOF){
		ll ans=1;
		for(int i=1;i<=pnum;++i){
			if(bit[i]%2)ans+=check(i);
			else ans-=check(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
