#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

int a[maxn],b[maxn];
int num[maxn];
int sum[maxn];
int rsum[maxn];
int vis[maxn];

int main(){
	int n;
	int q=0;
	while(scanf("%d",&n)!=EOF&&n){
		++q;
		sum[0]=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		for(int i=1;i<=n;++i)num[i]=a[i]-b[i];
		int minn=num[1];
		for(int i=1;i<=n;++i){
			sum[i]=sum[i-1]+num[i];
			if(sum[i]<minn)minn=sum[i];
		}
		minn=0-minn;
		int ans=0;
		rsum[n+1]=0;
		for(int i=n;i>=1;--i){
			rsum[i]=rsum[i+1]+num[i];
			if(rsum[i]>=minn){
				vis[i]=1;
				ans++;
			}
			else vis[i]=0;
		}
		printf("Case %d: ",q);
		for(int i=1;i<=n;++i){
			if(vis[i]){
				printf("%d",i);
				ans--;
				if(ans)printf(" ");
			}
		}
		printf("\n");
	}	
	return 0;
}
