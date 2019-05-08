#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e3+5;

int a[maxn][maxn];
int sum[maxn][maxn];
int n,m,k;

bool check(int mid){
	int s=0;
	for(int i=1;i<=n;++i){
		s+=sum[i][mid];
	}
	if(s>=k)return 1;
	return 0;
}

bool cmp(int a,int b){return a>b;}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=n;++i){
			sort(a[i]+1,a[i]+m+1,cmp);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]>=0)sum[i][j]=sum[i][j-1]+a[i][j];
				else sum[i][j]=sum[i][j-1];
			}
		}
		int ans=1005;
		int l=0,r=m;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				ans=min(ans,mid);
				r=mid-1;
			}
			else l=mid+1;
		}
		if(ans==1005)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
