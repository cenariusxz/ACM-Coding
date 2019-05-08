#include<stdio.h>
#include<algorithm>
using namespace std;
int n,x;
long long a[5000010];

void fuck()
{
	int i,l=1,r=1,rr=1;
	int ans=1e9;
	long long sum=0,s=0;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		sum+=a[i];
		r++;
		if(sum<=0){
			l=i+1;
			sum=0;
			continue;
		}
		if(sum<x){
			continue;
		}
		ans=min(ans,r-l+1);
		sum-=s;
		l=rr+1;
		for(
	}

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}
