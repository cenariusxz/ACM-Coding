#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[105];
int vis[2005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			vis[a[i]]++;
		}
		bool f=0;
		for(int i=2;i<=n;++i){
			for(int j=1;j<i;++j){
				if(a[i]==0&&a[j]==0){
					if(vis[0]>=3)f=1;
				}
				else if(a[i]==0||a[j]==0){
					if(vis[a[i]+a[j]]>=2)f=1;
				}
				else if(vis[a[i]+a[j]]>=1)f=1;
			}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
