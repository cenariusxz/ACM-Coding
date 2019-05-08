#include<stdio.h>
#include<string.h>
#include<math.h>
#include<set>
using namespace std;
typedef long long ll;

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			ll a,b,c,d;
			set<ll>S;
			S.clear();
			scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
			double ans=1e18;
			ll ans1=1;
			ll n;
			for(n=1;(c*1.0/d-a*1.0/b)*n<=((ll)(a%b))/(b*1.0);n++){
				if(S.find(((a%b)*(n%b))%b)==S.end()){
					S.insert(((a%b)*(n%b))%b);
				}
				else break;
				double p=c*1.0*n/d-((ll)((a*n)/b));
				if(p<ans){
					ans=p;
					ans1=n;
				}
			}
			printf("%lld\n",ans1);
		}
	}
	return 0;
}
