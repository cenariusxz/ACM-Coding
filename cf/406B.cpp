#include<stdio.h>
#include<string.h>
bool vis[1000005];
int ans[1000005];
int s=1000000;
int main(){
	int n,cnt=0;
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	int i,j;
	for(i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		vis[a]=1;
	}
	int nee=0;
	for(i=1;i<s+1-i;i++){
		j=s+1-i;
		if(vis[i]&&vis[j])nee++;
		else if(vis[i])ans[++cnt]=j;
		else if(vis[j])ans[++cnt]=i;
	}
	for(i=1;i<s+1-i&&nee;i++){
		j=s+1-i;
		if(!vis[i]&&!vis[j]){
			ans[++cnt]=i;
			ans[++cnt]=j;
			nee--;
		}
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
