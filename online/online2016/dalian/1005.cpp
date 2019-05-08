#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int h,k;
ll l;

void solve(){
	ll ans=0;
	for(int i=h;i>=1;i--){
		ll sz=l/i;
		int yu=l%i;
		int hz=k/i,hy=k%i;
		ll sh=sz/hz;
		int lhy=yu;
		if(sz%hz){
			sh++;
			k-(sz%hz)*i;
		}
		if(yu>lhy)ans=max(ans,sh+1);
		else ans=max(ans,sh);
	}
	printf("%lld\n",ans);
}

int main(){
	while(scanf("%d%lld%d",&h,&l,&k)!=EOF){
		solve();
	}
	return 0;
}
