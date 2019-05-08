#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

int a[maxn];
int maxx[maxn];

int main(){
	maxx[0]=-INF;
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)maxx[i]=max(maxx[i-1],a[i]+i);
		int ans=-INF;
		for(int i=2;i<=n;++i)ans=max(ans,a[i]-i+maxx[i-1]);
		printf("%d\n",-ans);
	}
	return 0;
}
