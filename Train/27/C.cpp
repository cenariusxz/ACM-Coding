#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		printf("Case #%d:\n",q);
		if(a==b){
			printf("1\n%lld %lld\n",a,a);
		}
		else{
			printf("2\n%lld %lld\n%lld %lld\n",a,b,b,a);
		}
	}
	return 0;
}
