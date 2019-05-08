#include<stdio.h>
#include<string.h>

struct xx{
	int x,y;
}x[2550];
int tx[55][55];

struct oo{
	int x,y;
}o[2550];

char t[55][55];
int no=0,nx=0;
int xx,yy;
bool vis[2550],tmp[2550];
int ans[105][105];

int main(){
	int n,i,j;
	scanf("%d",&n);
	memset(x,0,sizeof(x));
	memset(o,0,sizeof(o));
	memset(vis,0,sizeof(vis));
	memset(tx,0,sizeof(tx));
	memset(ans,0,sizeof(ans));
	ans[n][n]=2;
	for(i=1;i<=n;i++){
		scanf("%s",t[i]+1);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(t[i][j]=='o'){
				no++;
				o[no].x=i;
				o[no].y=j;
			}
			else if(t[i][j]=='x'){
				nx++;
				x[nx].x=i;
				x[nx].y=j;
				tx[i][j]=nx;
			}
			
		}
	}
	for(i=1;i<=nx;i++){
		memset(tmp,0,sizeof(tmp));
		tmp[i]=1;
		xx=x[i].x-o[1].x;
		yy=x[i].y-o[1].y;
		bool f=1;
		for(j=2;j<=no&&f;j++){
			int dx=o[j].x+xx,dy=o[j].y+yy;
			if(dx>n||dx<1||dy>n||dy<1){
				continue;
			}
			else if(tx[dx][dy]){
				tmp[tx[dx][dy]]=1;
			}
			else f=0;
		}
		if(f){
			for(int k=1;k<=nx;k++){
				if(tmp[k])vis[k]=1;
			}
			ans[n+xx][n+yy]=1;
		}
	}
	bool f=1;
	for(i=1;i<=nx;i++){
		if(!vis[i]){
			f=0;
		}
	}
	if(f){
		printf("YES\n");
		for(i=1;i<=2*n-1;i++){
			for(j=1;j<=2*n-1;j++){
				if(ans[i][j]==0)printf(".");
				else if(ans[i][j]==1)printf("x");
				else if(ans[i][j]==2)printf("o");
			}
			printf("\n");
		}
	}
	else printf("NO\n");
	return 0;
}
