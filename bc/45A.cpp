#include<stdio.h>
#include<string.h>
typedef long long ll;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll n;
		scanf("%lld",&n);
		int ans=0;
		bool f=0;
		while(n){
			if(n&1){
				if(!f)ans++;
				f=1;
			}
			else f=0;
			n>>=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
