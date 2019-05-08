#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
typedef long long ll;

const int maxn=5005;

int a[maxn];
int m[maxn<<1];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;++i){
			memset(m,0,sizeof(m));
			m[0+maxn]=1;
			int num=0;
			for(int j=i-1;j>=1;--j){
				if(a[j]<=a[i])num++;
				else num--;
				m[num+maxn]++;
			}
			int cnt=0;
			cnt+=m[0+maxn]+m[-1+maxn];
			num=0;
			for(int j=i+1;j<=n;++j){
				if(a[j]>=a[i])num++;
				else num--;
				cnt+=m[num+maxn]+m[num-1+maxn];
			}
		//	printf("%d ",cnt);
			ans+=cnt*(ll)a[i];
		}
	//	printf("\n");
		printf("%lld\n",ans);
	}
	return 0;
}
