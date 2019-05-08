#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
	ll m,r;
	scanf("%lld%lld",&m,&r);
	ll n=m-2;
	int i;
	ll ans1,ans2,maxx=0;
	if(m==1){
		ans1=2;
		ans2=0;
	}
	else if(m==2){
		ans1=8;
		ans2=2;
	}
	else if(m==3){
		ans1=18;
		ans2=8;
	}
	else{
		ans2=2*m*m-4*m+2;
		ans1=(m*m-n*(n-1))*2;
		for(i=1;i<n;i++){
			ans1+=4*i*(n-i+1);
//			if(4*i*(n-i+1)>maxx)maxx=4*i*(n-i+1);
		}
	}
	printf("%lld %lld",ans1,ans2);
	double ans=ans1*(double)r+ans2*(double)r*sqrt(2.0);
	printf("%.10lf\n",ans/(m*1.0*m));
	return 0;
}
