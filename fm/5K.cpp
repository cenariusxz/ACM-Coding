#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int pnum[500];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		ll a,b;
		int n;
		scanf("%lld%lld%d",&a,&b,&n);
		a--;
		ll ans=0;
		int cnt=0;
		for(int i=2;i*(ll)i<=n;++i){
			if(!(n%i)){
				pnum[++cnt]=i;
				while(!(n%i))n/=i;
			}
		}
		if(n>1)pnum[++cnt]=n;
		for(int i=1;i<(1<<cnt);++i){
			int bit=0;
			int mul=1;
			for(int j=1;j<=cnt;++j){
				if(i&(1<<(j-1))){
					bit++;
					mul*=pnum[j];
				}
			}
			if(bit%2)ans+=b/mul-a/mul;
			else ans-=b/mul-a/mul;
		}
		printf("Case #%d: %lld\n",q,b-a-ans);
	}
	return 0;
}
