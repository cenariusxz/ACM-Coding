#include<stdio.h>
#include<string.h>

struct point{
	char a;
	bool v;
}p[55][55];

int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};
int n,m,f1=0;

void dfs(int x,int y,int i,int j,int t){
	int k;
	t++;
	for(k=0;k<4;k++){
	//	printf("%d %d\n",x,y);
		int dx=x+xx[k],dy=y+yy[k];
		if(dx>=1&&dx<=n&&dy>=1&&dy<=m){
			if(dx==i&&dy==j&&t>=4){
				f1=1;
			}
			if(!p[dx][dy].v&&p[dx][dy].a==p[i][j].a){
				p[dx][dy].v=1;
				dfs(dx,dy,i,j,t);
			}
		}
	}
}

int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	int cnt=0;
	while(cnt<n*m){
		char c=getchar();
		if(c>='A'&&c<='Z'){
			cnt++;
			int x=(cnt-1)/m+1,y=cnt-((cnt-1)/m)*m;
			p[x][y].a=c;
			p[x][y].v=0;
		//	printf("%d %d %c\n",(cnt-1)/m+1,cnt-((cnt-1)/m)*m,c);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			int ans=0;
			for(k=0;k<4;k++){
				int dx=i+xx[k],dy=j+yy[k];
				if(dx>=1&&dx<=n&&dy>=1&&dy<=m){
					if(p[i][j].a==p[dx][dy].a)ans++;
				}
			}
			if(ans<2)p[i][j].v=1;
		}
	}/*
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)printf("%d ",p[i][j].v);
		printf("\n");
	}*/
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!p[i][j].v){
				p[i][j].v=1;
				int t=1;
				dfs(i,j,i,j,t);
			}
		}
	}
	if(f1)printf("Yes\n");
	else printf("No\n");
}
