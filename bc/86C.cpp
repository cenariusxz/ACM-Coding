#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+5;

int a[maxn];
int pos[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		pos[0]=0;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i]>=m)pos[++cnt]=i;
		}
		pos[cnt+1]=n+1;
		ll sum=0;
		if(cnt<k-1)printf("0\n");
		else{
			for(int i=k;i<=cnt;++i){
				int l=i-k+1,r=i;
			//	printf("%d %d %d %d\n",pos[l-1],pos[l],pos[r],pos[r+1]);
				sum+=(pos[l]-pos[l-1])*(ll)(pos[cnt+1]-pos[r]);
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}
