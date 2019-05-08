#include<stdio.h>
#include<string.h>

bool vis[1005][1005];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	memset(vis,0,sizeof(vis));
	int i,j,a,b;
	for(i=1;i<=k;i++){
		scanf("%d%d",&a,&b);
		vis[a][b]=1;
		if(vis[a-1][b]&&vis[a][b-1]&&vis[a-1][b-1])break;
		if(vis[a-1][b]&&vis[a-1][b+1]&&vis[a][b+1])break;
		if(vis[a][b+1]&&vis[a+1][b+1]&&vis[a+1][b])break;
		if(vis[a+1][b]&&vis[a][b-1]&&vis[a+1][b-1])break;
	}
	if(i==k+1)printf("0\n");
	else printf("%d\n",i);
	for(i;i<k;i++)scanf("%d%d",&a,&b);
}
