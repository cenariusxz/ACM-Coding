#include<stdio.h>
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
	int x,y,z;
	ll a,b,tmp1,tmp2,tmp3,tmp4,ans1,ans2;
	while(scanf("%d%d%d%I64d%I64d",&x,&y,&z,&a,&b)!=EOF){
		tmp1=x/gcd(x,y)*y;
		tmp2=y/gcd(y,z)*z;
		tmp3=x/gcd(x,z)*z;
		tmp4=tmp3/gcd(tmp3,y)*y;
		ans1=(a-1)/x+(a-1)/y+(a-1)/z-(a-1)/tmp1-(a-1)/tmp2-(a-1)/tmp3+(a-1)/tmp4;
		ans2=b/x+b/y+b/z-b/tmp1-b/tmp2-b/tmp3+b/tmp4;
		printf("%I64d\n",ans2-ans1);
	}
	return 0;
}
