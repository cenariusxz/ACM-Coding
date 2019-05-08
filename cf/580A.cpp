#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

int a[maxn];
int dp[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	dp[0]=0;
	a[0]=-1;
	int maxx=0;
	for(int i=1;i<=n;++i){
		if(a[i]>=a[i-1])dp[i]=dp[i-1]+1;
		else dp[i]=1;
		if(dp[i]>maxx)maxx=dp[i];
	}
	printf("%d\n",maxx);
	return 0;
}
