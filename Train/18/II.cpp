#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;

int n,m;
ll k;
ll w[maxn],t[maxn];
ll sum[maxn];

int main(){
	scanf("%d%d%lld\n",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&w[i]);
	sum[0]=0;
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+w[i];
	for(int i=1;i<=m;++i)scanf("%lld",&t[i]);
	int pos=0;
	for(int i=1;i<=n;++i){
		while(sum[i]-sum[pos]>=k)++pos;
		
	}
	return 0;
}
