#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int vis[1005];
int a[200005],h[200005];

int main(){
	int n;
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	int sum=0;
	int maxx=0,prex=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&h[i]);
		vis[h[i]]++;
		if(h[i]>maxx)maxx=h[i];
		sum+=a[i];
	}
	if(vis[maxx]>=2){
		prex=maxx;
	}
	else{
		for(int i=maxx-1;i>=1;i--){
			if(vis[i]){
				prex=i;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(h[i]==maxx)printf("%d ",prex*(sum-a[i]));
		else printf("%d ",maxx*(sum-a[i]));
	}
	printf("\n");
}
