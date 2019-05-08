#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int d[55][55];
int dis[2][55][55][4];
int dir[1005];
int xx[4]={0,0,-1,1};
int yy[4]={1,-1,0,0};

void init(){
	memset(d,0,sizeof(d));
	memset(dis,0,sizeof(dis));
	memset(dir,-1,sizeof(dir));
}

int main(){
	int n,x0,y0,t;
	while(scanf("%d%d%d%d",&n,&x0,&y0,&t)!=EOF){
		init();
		while(n--){
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2){
				if(y1>y2)swap(y1,y2);
				for(int i=y1;i<=y2;++i){
					if(i!=y2)d[x1][i]|=(1<<0);
					if(i!=y1)d[x1][i]|=(1<<1);
				}
			}
			if(y1==y2){
				if(x1>x2)swap(x1,x2);
				for(int i=x1;i<=x2;++i){
					if(i!=x1)d[i][y1]|=(1<<2);
					if(i!=x2)d[i][y1]|=(1<<3);
				}
			}
		}
		int m=0;
		for(int i=1;i<=t;++i){
			int len;
			char s[10];
			scanf("%d%s",&len,s);
			m+=len;
			if(s[0]=='N')dir[m]=0;
			if(s[0]=='S')dir[m]=1;
			if(s[0]=='W')dir[m]=2;
			if(s[0]=='E')dir[m]=3;
		}
		for(int i=0;i<=3;++i)dis[0][x0][y0][i]=1;
		for(int p=1;p<=m;++p){
			int now=p&1;
			int pre=now^1;
			for(int i=0;i<=50;++i){
				for(int j=0;j<=50;++j){
					for(int k=0;k<=3;++k){
						if(!dis[pre][i][j][k])continue;
						if(!(d[i][j]&(1<<k)))continue;
						int dx=i+xx[k],dy=j+yy[k];
						if(dir[p]==-1||k==dir[p]){
							if(k==0){
								dis[now][dx][dy][0]=1;
								dis[now][dx][dy][2]=1;
								dis[now][dx][dy][3]=1;
							}
							if(k==1){
								dis[now][dx][dy][1]=1;
								dis[now][dx][dy][2]=1;
								dis[now][dx][dy][3]=1;
							}
							if(k==2){
								dis[now][dx][dy][2]=1;
								dis[now][dx][dy][0]=1;
								dis[now][dx][dy][1]=1;
							}
							if(k==3){
								dis[now][dx][dy][3]=1;
								dis[now][dx][dy][0]=1;
								dis[now][dx][dy][1]=1;
							}
						}
						else{
							if(dir[p]!=(k^1))dis[now][dx][dy][dir[p]]=1;
						}
					}
				}
			}
			memset(dis[pre],0,sizeof(dis[pre]));
		}
		for(int i=0;i<=50;++i){
			for(int j=0;j<=50;++j){
				for(int k=0;k<=3;++k){
					if(dis[m&1][i][j][k]&&(d[i][j]&(1<<k))){
						printf("%d %d\n",i,j);
						break;
					}
				}
			}
		}
	}
	return 0;
}
