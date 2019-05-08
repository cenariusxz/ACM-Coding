#include<string.h>
#include<stdio.h>
typedef long long ll;
const int maxn=2e5+5;

int a[maxn];
ll la[maxn],ra[maxn];

int main(){
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	ll mul=1;
	for(int i=1;i<=k;++i)mul*=x;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		la[i]=la[i-1]|a[i];
	}
	for(int i=n;i>=1;--i){
		ra[i]=ra[i+1]|a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ll tmp=la[i-1]|ra[i+1]|(a[i]*mul);
		if(tmp>ans)ans=tmp;
	}
	printf("%I64d\n",ans);
	return 0;
}
