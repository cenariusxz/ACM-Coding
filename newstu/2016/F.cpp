#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=2e5+5;
typedef long long ll;

int main(){
	int n;
	ll ans=0;
	scanf("%d",&n);
	int pre=0;
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		if(a>pre)ans+=a-pre;
		pre=a;
	}
	printf("%lld\n",ans);
	return 0;
}
