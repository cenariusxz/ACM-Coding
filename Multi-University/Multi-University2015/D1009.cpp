#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int n,m,maxx;
char ma[1005][1005];
int px[2][2000],py[2][2000],cnt[2];
bool vis[1005][1005];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char ans[1000005];

int max(int a,int b){
	return a>b?a:b;
}

void dfs(int x,int y){
	if(x+y>maxx){
		maxx=x+y;
		cnt[1]=1;
		px[1][cnt[1]]=x;
		py[1][cnt[1]]=y;
	}
	else if(x+y==maxx){
		cnt[1]++;
		px[1][cnt[1]]=x;
		py[1][cnt[1]]=y;
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&ma[xx][yy]=='0'&&!vis[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,j;
		int aa=0;
		maxx=cnt[1]=0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%s",ma[i]+1);
		}
		aa=0;
		if(ma[1][1]=='0'){
			vis[1][1]=1;
			dfs(1,1);
			memset(vis,0,sizeof(vis));
			cnt[0]=0;
			for(i=1;i<=cnt[1];i++){
				int xx=px[1][i]+1,yy=py[1][i];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
					cnt[0]++;
					px[0][cnt[0]]=xx;
					py[0][cnt[0]]=yy;
					vis[xx][yy]=1;
				}
				xx=px[1][i],yy=py[1][i]+1;
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
					cnt[0]++;
					px[0][cnt[0]]=xx;
					py[0][cnt[0]]=yy;
					vis[xx][yy]=1;
				}
			}
			if(cnt[0]>0)ans[aa++]='1';
		}
		else{
			cnt[0]=1;
			px[0][cnt[0]]=1;
			py[0][cnt[0]]=1;
			ans[aa++]='1';
		}
		bool f1=0,f0=0,f=0;
		int pos=px[0][1]+py[0][1];
		memset(vis,0,sizeof(vis));
		while(pos<n+m){
			f1=0,f0=0;
			for(i=1;i<=cnt[f];i++){
				int xx=px[f][i]+1;
				int yy=py[f][i];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
					if(ma[xx][yy]=='1')f1=1;
					else f0=1;
				}
				xx--;
				yy++;
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
					if(ma[xx][yy]=='1')f1=1;
					else f0=1;
				}
			}
			cnt[!f]=0;
			if(f0){
				ans[aa++]='0';
				for(i=1;i<=cnt[f];i++){
					int xx=px[f][i]+1;
					int yy=py[f][i];
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
						if(ma[xx][yy]=='0'){
							px[!f][++cnt[!f]]=xx;
							py[!f][cnt[!f]]=yy;
						}
						vis[xx][yy]=1;
					}
					xx--;
					yy++;
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
						if(ma[xx][yy]=='0'){
							px[!f][++cnt[!f]]=xx;
							py[!f][cnt[!f]]=yy;
						}
						vis[xx][yy]=1;
					}
				}
			}
			else if(f1){
				ans[aa++]='1';
				for(i=1;i<=cnt[f];i++){
					int xx=px[f][i]+1;
					int yy=py[f][i];
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
						px[!f][++cnt[!f]]=xx;
						py[!f][cnt[!f]]=yy;
						vis[xx][yy]=1;
					}
					xx--;
					yy++;
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
						px[!f][++cnt[!f]]=xx;
						py[!f][cnt[!f]]=yy;
						vis[xx][yy]=1;
					}
				}

			}
			pos++;
			f=!f;
		}
		ans[aa]=0;
		if(aa==0)printf("0\n");
		else printf("%s\n",ans);
	}
	return 0;
}
