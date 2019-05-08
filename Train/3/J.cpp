#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,shu[510][510],hen[510][510],g[510][510];
bool vis[510][510];

void fuck()
{
	int i,j,k,x,y,xx,yy,a,b,c;
	memset(shu,0,sizeof(shu));
	memset(hen,0,sizeof(hen));
	memset(vis,0,sizeof(vis));
	memset(g,0,sizeof(g));
	scanf("%d%d",&xx,&yy);
	for(i=2;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x==xx){
			c=x;
			a=min(y,yy);
			b=max(y,yy);
			for(j=a;j<b;j++)
				shu[c][j]=1;
		}
		if(y==yy){
			c=y;
			a=min(x,xx);
			b=max(x,xx);
			for(j=a;j<b;j++)
				hen[j][c]=1;
		}
		xx=x;yy=y;
	}
	for(i=0;i<=500;i++){
		bool f=0;
		for(j=0;j<=500;j++){
			f^=hen[i][j];
			g[i][j]=f;
		}
	}
	/*for(i=0;i<=7;i++){
		for(j=0;j<=7;j++){
			printf("%d",g[i][j]);
		}
		puts("");
	}*/
	scanf("%d%d",&xx,&yy);
	for(i=2;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x==xx){
			c=x;
			a=min(y,yy);
			b=max(y,yy);
			for(j=a;j<b;j++){
				k=c;
				while(k<=500&&g[k][j]) vis[k++][j]=1;
				k=c-1;
				while(k>=0&&g[k][j]) vis[k--][j]=1;
			}
		}
		if(y==yy){
			c=y;
			a=min(x,xx);
			b=max(x,xx);
			for(j=a;j<b;j++){
				k=c;
				while(k<=500&&g[j][k]) vis[j][k++]=1;
				k=c-1;
				while(k>=0&&g[j][k]) vis[j][k--]=1;
			}
		}
		xx=x;yy=y;
	}
	int cnt=0;
	/*for(i=0;i<=7;i++){
		for(j=0;j<=7;j++){
			printf("%d",vis[i][j]);
		}
		puts("");
	}*/
	for(i=0;i<=500;i++)
		for(j=0;j<=500;j++)
			cnt+=vis[i][j];
	printf("%d\n",cnt);
}
int main()
{
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		fuck();
	}
}

