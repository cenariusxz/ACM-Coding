#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		ll sum=0;
		for(int i=1;i<=n;++i){
			ll a;
			scanf("%lld",&a);
			sum+=a;
		}
		while(m--){
			ll a;
			scanf("%lld",&a);
			if(a<=sum)printf("0");
			else printf("1");
		}
		printf("\n");
	}

	return 0;
}
