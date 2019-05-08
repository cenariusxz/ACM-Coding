#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int get(ll a){
	int c=1;
	while(!(a&1)){
		a>>=1;
		c++;
	}
	return c;
}

int main(){
	ll n;
	while(scanf("%lld",&n)!=EOF){
		int c=62;
		while((1ll<<c)-1>n){
			c--;
		}
		if((1ll<<c)-1==n)printf("%d\n",c);
		else{
			int ans=0;
			ll tmp=n-((1ll<<c)-1);
			if(tmp==(1ll<<(c-1)))ans=c+1;
			else if(tmp<(1ll<<(c-1))){
				ans=c-1;
			/*	if(tmp%2)ans+=c;
				else*/ ans+=c+1-get(tmp);
			}
			else{
				tmp-=(1ll<<(c-1));
				ans=c;
			//	if(tmp%2)ans+=c;
			/*	else*/ ans+=c+1-get(tmp);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
