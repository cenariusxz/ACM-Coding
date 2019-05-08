#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=20005;

int n,m,d;
int dis[maxn];

bool check(int mid){
//	printf("\n%d\n",mid);
	int lpre=dis[1]-mid,rpre=dis[1]+mid;
	int ltmp,rtmp;
	for(int i=2;i<=m;++i){
		lpre+=d;rpre+=d;
//		printf("%d %d\n",lpre,rpre);
		ltmp=dis[i]-mid,rtmp=dis[i]+mid;
		if(rpre<ltmp||lpre>rtmp){
			return 0;
		}
		lpre=max(lpre,ltmp);
		rpre=min(rpre,rtmp);
	}
//	printf("aaa:%d %d\n",lpre,rpre);
	lpre-=n;
	rpre-=n;
	lpre+=d;
	rpre+=d;
//	printf("%d %d\n",lpre,rpre);
	ltmp=dis[1]-mid,rtmp=dis[1]+mid;
	if(rpre<ltmp||lpre>rtmp){
		return 0;
	}
	return 1;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)scanf("%d",&dis[i]);
		sort(dis+1,dis+m+1);
		int l=0,r=(n+1)/2;
		int ans=0x3f3f3f3f;
		d=n/m;
		while(l<=r){
			int mid=l+((r-l)>>1);
			if(check(mid)){
				if(mid<ans)ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}
