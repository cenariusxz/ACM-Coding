#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[100005],b[100005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=m;i++){
			scanf("%d",&b[i]);
		}
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		int pos1=n,pos2=1;
		ll ans=0;
		while(a[pos1]>b[pos2]&&pos1>=1&&pos2<=m){
			ans+=a[pos1]-b[pos2];
			pos1--;
			pos2++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
