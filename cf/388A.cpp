#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int x[105];
int vis[105];
int p[105];

int main(){
	int n;
	scanf("%d",&n);
	int i,ans=0;
	int maxx=0;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		scanf("%d",&x[i]);
		vis[x[i]]++;
		if(x[i]>maxx)maxx=x[i];
	}
	int cnt=0;
	while(cnt<=n){
		memset(p,-1,sizeof(p));
		p[maxx]=-1;
		bool f=1;
		for(i=0;i<=maxx&&f;i++){
			if(vis[i])f=0;
		}
		if(f)break;
		for(i=maxx;i>=0;i--){
			if(vis[i]){
				vis[i]--;
				cnt++;
				if(i+1<=maxx){
					if(vis[i+1]){
						p[i]=i+1;
					}
					else{
						p[i]=p[i+1];
					}
				}
			}
			else{
				if(i+1<=maxx){
					if(vis[i+1]){
						vis[i+1]--;
						cnt++;
						if(vis[i+1])p[i]=i+1;
						else p[i]=p[i+1];
					}
					else{
						if(p[i+1]!=-1&&vis[p[i+1]]){
							vis[p[i+1]]--;
							cnt++;
							if(vis[p[i+1]]){
								p[i]=p[i+1];
							}
							else p[i]=p[p[i+1]];
						}
					}
				}
			}	
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
