#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int x[50005],s[50005];
bool vis[50005];
int w,n;

bool judge(int l){
	int i,j;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	int pos=2;
	for(i=1;i<=n;i++){
		if(vis[i]){
			int sum2=s[n]-s[i-1],cnt2=n-i;
			if(sum2+cnt2<=w){
				return 1;
			}
			bool f=1;
			for(j=pos;j<=n;j++){
				int sum=s[j]-s[i-1],cnt=j-i;
				if(sum+cnt>w)break;
				if(sum+l*cnt>=w){
					vis[j+1]=1;
				}
				pos=j+1;
			}
		}
	}
	return 0;
}

int main(){
	while(scanf("%d%d",&w,&n)!=EOF&&(w+n)){
		int i,j;
		memset(s,0,sizeof(s));
		for(i=1;i<=n;i++){
			scanf("%d",&x[i]);
			s[i]=s[i-1]+x[i];
		}
//		for(i=1;i<=n;i++)printf("%d ",s[i]);
//		printf("\n");
		int l=1,r=w;
		while(l<=r){
			int mid=l+((r-l)>>1);
		//	printf("%d %d %d %d\n",l,r,mid,judge(mid));
	//		if(mid==2)printf("%d\n",judge(mid));
			if(judge(mid)){
				r=mid-1;
			}
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
