#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[1000000+10];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int b;
		int i;
		for(i=1;i<=n;i++)scanf("%d%d",&b,&a[i]);
		sort(a+1,a+n+1);
		long long ans=0;
		for(i=1;i<=n;i++){
			long long tmp=a[i]-a[n/2+1];
			ans+=tmp>0?tmp:-tmp;

		}
		printf("%lld\n",ans);
	}
	return 0;
}
