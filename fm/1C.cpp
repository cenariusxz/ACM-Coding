#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[1000005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j;
		ll sum=0;
		a[0]=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		ll num=sum/n;
		for(i=1;i<=n;i++){
			a[i]=a[i-1]+a[i]-num;
		}
		sort(a+1,a+n+1);
		sum=0;
		for(i=1;i<=n;i++){
			sum+=a[i]-a[n/2+1]>=0?a[i]-a[n/2+1]:a[n/2+1]-a[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
