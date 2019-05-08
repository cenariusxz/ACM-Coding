#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int p[22],g[22][22];
int n,m;

void fuck()
{
	int i,j,k,x,y,z;
	memset(g,0x3f,sizeof(g));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		p[x]=y-1;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x][y]=min(g[x][y],z);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(p[i]==p[j]) g[i][j]=g[j][i]=0;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
	int f;
	do{
		f=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(p[j]>p[i]+g[i][j]){
					p[j]=p[i]+g[i][j];
					f=1;
				}
	}while(f);
	for(i=1;i<=n;i++){
		printf("%d %d\n",i,p[i]);
	}
	int ans=0;
	int v[100]={0};
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j==i) continue;
			for(k=j+1;k<=n;k++){
				if(k==i||k==j) continue;
				if(p[i]==p[j]+p[k]) v[i]=1;
			}
		}
		ans+=v[i];
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}
