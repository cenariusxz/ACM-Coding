#include<stdio.h>
#include<string.h>

int g[105][105];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int a,b,i,j,k;
		memset(g,0,sizeof(g));
		for(i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			g[a][b]=1;
		}
		for(k=1;k<=n;k++){
			for(j=1;j<=n;j++){
				for(i=1;i<=n;i++){
					if(g[i][k]&&g[k][j])g[i][j]=1;
				}
			}
		}
		int ans=0;
		for(i=1;i<=n;i++){
			int t=0;
			for(j=1;j<=n;j++){
				if(g[i][j])t++;
				if(g[j][i])t++;
			}
			if(t==n-1)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
