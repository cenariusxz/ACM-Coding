#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
	int n;
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		ans=ans+a+(i-1)*(ll)(a-1);
	}
	printf("%I64d\n",ans);
	return 0;
}
