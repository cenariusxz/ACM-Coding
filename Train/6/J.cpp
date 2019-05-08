#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

/*ll exgcd(ll a,ll b,ll &d,ll &x,ll &y){
	if(!b){
		d=a;x=1;y=0;
		return x;
	}
	else{
		exgcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
	return x;
}*/

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1;y=0;return a;}
	ll r=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return r;
}

ll Abs(ll a){return a>0?a:-a;}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll d1,d2,f1,f2,n1,n2;
		scanf("%lld%lld%lld%lld%lld%lld",&n1,&f1,&d1,&n2,&f2,&d2);
		ll x,y,a=d1,b=-d2;
		ll d=f2-f1;
		ll g=gcd(a,b);
	//	printf("%lld\n",g);
		ll Lcm=a/g*b;
		exgcd(a,b,x,y);
		x=x*d/g;
		y=y*d/g;
		ll ff=f1+x*d1;
		ff=ff+(max(f1,f2)-ff)/Lcm*Lcm;
		if(ff<max(f1,f2))ff+=Abs(Lcm);
		ll pos1=(ff-f1)/d1+1;
		ll pos2=(ff-f2)/d2+1;
		if(pos1>n1||pos2>n2){
			printf("0\n");
			continue;
		}
		Lcm=d1/gcd(d1,d2)*d2;
		ll dis1=Lcm/d1;
		ll dis2=Lcm/d2;
		ll ans1=(n1-pos1)/dis1+1;
		ll ans2=(n2-pos2)/dis2+1;
		if(ans1<=0||ans2<=0)printf("0\n");
		else printf("%lld\n",min(ans1,ans2));
	}
	return 0;
}
