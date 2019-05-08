#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
typedef long long ll;

ll a[200005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
	map<ll,ll>m1;
	map<ll,ll>m2;
	ll ans=0;
	for(i=1;i<=n;i++){
		ll tmp=a[i]/k;
		if(tmp*k==a[i]){
			ans+=m2[tmp];
			m2[a[i]]+=m1[tmp];
		}
		m1[a[i]]++;
	}
	printf("%I64d\n",ans);
	return 0;
}
