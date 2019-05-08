#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;
const int INF=0x3f3f3f3f;

int cx,cy,cz;
int vis[3][maxn];

struct xoy{
	int x1,y1,x2,y2,z;
	bool operator < (const xoy a)const{
		return z<a.z;
	}
}z[maxn];

struct yoz{
	int y1,z1,y2,z2,x;
	bool operator < (const yoz a)const{
		return x<a.x;
	}
}x[maxn];

struct xoz{
	int x1,z1,x2,z2,y;
	bool operator < (const xoz a)const{
		return y<a.y;
	}
}y[maxn];

inline bool check1(int x,int z,int x1,int z1,int x2,int z2){
	return (x>x1)&&(x<x2)&&(z>z1)&&(z<z2);
}

inline bool check2(int x,int y,int x1,int y1,int x2,int y2){
	return (x>x1)&&(x<x2)&&(y>y1)&&(y<y2);
}

inline bool check3(int y,int z,int y1,int z1,int y2,int z2){
	return (y>y1)&&(y<y2)&&(z>z1)&&(z<z2);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		cx=0,cy=0,cz=0;
		while(n--){
			int x1,y1,z1,x2,y2,z2;
			memset(vis,0,sizeof(vis));
			scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
			if(x1==x2){
				++cx;
				x[cx].x=x1;
				x[cx].y1=min(y1,y2);
				x[cx].y2=max(y1,y2);
				x[cx].z1=min(z1,z2);
				x[cx].z2=max(z1,z2);
			}
			if(y1==y2){
				++cy;
				y[cy].y=y1;
				y[cy].x1=min(x1,x2);
				y[cy].x2=max(x1,x2);
				y[cy].z1=min(z1,z2);
				y[cy].z2=max(z1,z2);
			}
			if(z1==z2){
				++cz;
				z[cz].z=z1;
				z[cz].x1=min(x1,x2);
				z[cz].x2=max(x1,x2);
				z[cz].y1=min(y1,y2);
				z[cz].y2=max(y1,y2);
			}
		}
		sort(x+1,x+cx+1);
		sort(y+1,y+cy+1);
		sort(z+1,z+cz+1);
		bool f=1;

		for(int i=1;i<=cx&&f;++i){
			if(vis[0][i])continue;/*
			int l=1,r=cy,m;
			int pos=INF;
			while(l<=r){
				m=l+((r-l)>>1);
				if(y[m].y>x[i].y1){
					pos=min(pos,m);
					r=m-1;
				}
				else l=m+1;
			}*/
			for(int j=1;j<=cy&&f&&!vis[0][i];++j){
				if(y[j].y<=x[i].y1)continue;
				if(y[j].y>=x[i].y2)break;
				int tmp=0;
				tmp+=check1(x[i].x,x[i].z1,y[j].x1,y[j].z1,y[j].x2,y[j].z2);
				tmp+=check1(x[i].x,x[i].z2,y[j].x1,y[j].z1,y[j].x2,y[j].z2);
				if(tmp==1){
					vis[0][i]=1;
					vis[1][j]=1;
				}
			}/*
			l=1,r=cz,pos=INF;
			while(l<=r){
				m=l+((r-l)>>1);
				if(z[m].z>x[i].z1){
					pos=min(pos,m);
					r=m-1;
				}
				else l=m+1;
			}*/
			for(int j=1;j<=cz&&f&&!vis[0][i];++j){
				if(z[j].z<=x[i].z1)continue;
				if(z[j].z>=x[i].z2)break;
				int tmp=0;
				tmp+=check2(x[i].x,x[i].y1,z[j].x1,z[j].y1,z[j].x2,z[j].y2);
				tmp+=check2(x[i].x,x[i].y2,z[j].x1,z[j].y1,z[j].x2,z[j].y2);
				if(tmp==1){
					vis[0][i]=1;
					vis[2][j]=1;
				}
			}
			if(!vis[0][i])f=0;
		}

		for(int i=1;i<=cy&&f;++i){
			if(vis[1][i])continue;/*
			int l=1,r=cx,m;
			int pos=INF;
			while(l<=r){
				m=l+((r-l)>>1);
				if(x[m].x>y[i].x1){
					pos=min(pos,m);
					r=m-1;
				}
				else l=m+1;
			}*/
			for(int j=1;j<=cx&&f&&!vis[1][i];++j){
				if(x[j].x<=y[i].x1)continue;
				if(x[j].x>=y[i].x2)break;
				int tmp=0;
				tmp+=check3(y[i].y,y[i].z1,x[j].y1,x[j].z1,x[j].y2,x[j].z2);
				tmp+=check3(y[i].y,y[i].z2,x[j].y1,x[j].z1,x[j].y2,x[j].z2);
				if(tmp==1){
					vis[1][i]=1;
					vis[0][j]=1;
				}
			}/*
			l=1,r=cz,pos=INF;
			while(l<=r){
				m=l+((r-l)>>1);
				if(z[m].z>y[i].z1){
					pos=min(pos,m);
					r=m-1;
				}
				else l=m+1;
			}*/
			for(int j=1;j<=cz&&f&&!vis[1][i];++j){
				if(z[j].z<=y[i].z1)continue;
				if(z[j].z>=y[i].z2)break;
				int tmp=0;
				tmp+=check2(y[i].x1,y[i].y,z[j].x1,z[j].y1,z[j].x2,z[j].y2);
				tmp+=check2(y[i].x2,y[i].y,z[j].x1,z[j].y1,z[j].x2,z[j].y2);
				if(tmp==1){
					vis[1][i]=1;
					vis[2][j]=1;
				}
			}
			if(!vis[1][i])f=0;
		}

		for(int i=1;i<=cz&&f;++i){
			if(vis[2][i])continue;/*
			int l=1,r=cx,m;
			int pos=INF;
			while(l<=r){
				m=l+((r-l)>>1);
				if(x[m].x>z[i].x1){
					pos=min(pos,m);
					r=m-1;
				}
				else l=m+1;
			}*/
			for(int j=1;j<=cx&&f&&!vis[2][i];++j){
				if(x[j].x<=z[i].x1)continue;
				if(x[j].x>=z[i].x2)break;
				int tmp=0;
				tmp+=check3(z[i].y1,z[i].z,x[j].y1,x[j].z1,x[j].y2,x[j].z2);
				tmp+=check3(z[i].y2,z[i].z,x[j].y1,x[j].z1,x[j].y2,x[j].z2);
				if(tmp==1){
					vis[2][i]=1;
					vis[0][j]=1;
				}
			}/*
			l=1,r=cy,pos=INF;
			while(l<=r){
				m=l+((r-l)>>1);
				if(y[m].y>z[i].y1){
					pos=min(pos,m);
					r=m-1;
				}
				else l=m+1;
			}*/
			for(int j=1;j<=cz&&f&&!vis[2][i];++j){
				if(y[j].y<=z[i].y1)continue;
				if(y[j].y>=z[i].y2)break;
				int tmp=0;
				tmp+=check1(z[i].x1,z[i].z,y[j].x1,y[j].z1,y[j].x2,y[j].z2);
				tmp+=check1(z[i].x2,z[i].z,y[j].x1,y[j].z1,y[j].x2,y[j].z2);
				if(tmp==1){
					vis[2][i]=1;
					vis[0][j]=1;
				}
			}
			if(!vis[2][i])f=0;
		}

		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
