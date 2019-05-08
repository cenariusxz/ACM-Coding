#include<stdio.h>
#include<string.h>
using namespace std;

const int maxn=1e6+5;
const int maxm=1e5+5;

int fa[maxn],v[105][105][105],f[maxn];
int n;
int x[maxm],y[maxm],z[maxm];
int xx[6]={1,-1,0,0,0,0};
int yy[6]={0,0,1,-1,0,0};
int zz[6]={0,0,0,0,1,-1};

inline int GetId(int x,int y,int z){
	return (z-1)*10000+(y-1)*100+x;
}

void init(){
	memset(f,0,sizeof(f));
	memset(v,0,sizeof(v));
	for(int i=0;i<maxn;++i)fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		bool flag=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
			if(v[x[i]][y[i]][z[i]])flag=1;
			else v[x[i]][y[i]][z[i]]=1;
		}
		if(flag){
			printf("No\n");
			continue;
		}
		for(int i=100;i>=1;--i){
			for(int j=100;j>=1;--j){
				for(int k=100;k>=1;--k){
					int id1=GetId(i,j,k);
					if(i==100||j==100||k==100||i==1||j==1)f[find(id1)]=1;
					if(!v[i][j][k]){
						int dx=i-1,dy=j,dz=k;
						if(dx>=1&&dx<=100){
							int id2=GetId(dx,dy,dz);
							if(!v[dx][dy][dz]){
								int X=find(id1),Y=find(id2);
								if(X!=Y){
									if(f[X]==1)fa[Y]=X;
									else fa[X]=Y;
								}
							}
						}
						dx=i,dy=j-1,dz=k;
						if(dy>=1&&dy<=100){
							int id2=GetId(dx,dy,dz);
							if(!v[dx][dy][dz]){
								int X=find(id1),Y=find(id2);
								if(X!=Y){
									if(f[X]==1)fa[Y]=X;
									else fa[X]=Y;
								}
							}
						}
						dx=i,dy=j,dz=k-1;
						if(dz>=1&&dz<=100){
							int id2=GetId(dx,dy,dz);
							if(!v[dx][dy][dz]){
								int X=find(id1),Y=find(id2);
								if(X!=Y){
									if(f[X]==1)fa[Y]=X;
									else fa[X]=Y;
								}
							}
						}

					}
				}
			}
		}
		flag=0;
		for(int i=n;i>=1;--i){
			int ddx=x[i],ddy=y[i],ddz=z[i];
			int id1=GetId(ddx,ddy,ddz);
			if(ddx==100||ddy==100||ddz==100||ddx==1||ddy==1)f[find(id1)]=1;
			int cnt=0,c=0;
			for(int j=0;j<6;++j){
				int dx=ddx+xx[j],dy=ddy+yy[j],dz=ddz+zz[j];
				if(dx>=1&&dx<=100&&dy>=1&&dy<=100&&dz>=1&&dz<=100){
					c++;
					if(v[dx][dy][dz]==0){
						cnt++;
						int id2=GetId(dx,dy,dz);
						int X=find(id1),Y=find(id2);
						if(X!=Y){
							if(f[Y])fa[X]=Y;
							else fa[Y]=X;
						}
					}
				}
			}
			if(cnt==c&&ddz!=1){
				flag=1;
				break;
			}
			int X=find(id1);
			if(!f[X]){
				flag=1;
				break;
			}
			v[ddx][ddy][ddz]=0;
		}
		if(flag)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}

