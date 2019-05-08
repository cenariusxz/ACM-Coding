#include<stdio.h>

int vis[500005];
int main(){
	int n=500000;
	for(int i=1;i<=n;++i){
		int t=n/i;
		if(n%i)t++;
		vis[t]=1;
	}
	int ans=0;
	for(int i=1;i<=n;++i)if(vis[i])ans++;
	printf("%d\n",ans);
}
