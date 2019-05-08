#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=10500;

int fa[maxn];
ll num[maxn];
int x[150],y[150];
int cx,cy;

struct rect{
	int l,t,r,b;
}a[55];

int find(int x){
	int r=x,t;
	while(r!=fa[r])r=fa[r];
	while(x!=r){
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		cx=0,cy=0;
		x[cx]=-1,y[cy]=-1;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d%d",&a[i].l,&a[i].t,&a[i].r,&a[i].b);
			x[++cx]=a[i].l;
			x[++cx]=a[i].r;
			y[++cy]=a[i].t;
			y[++cy]=a[i].b;
		}
		int cntx=cx,cnty=cy;
		sort(x+1,x+cx+1);
		sort(y+1,y+cy+1);
		cx=1;cy=1;
		for(int i=2;i<=cntx;++i){
			if(x[i]!=x[i-1])x[++cx]=x[i];
		}
		x[++cx]=1000001;
		for(int i=2;i<=cnty;++i){
			if(y[i]!=y[i-1])y[++cy]=y[i];
		}
		y[++cy]=1000001;
		for(int i=1;i<=cx;++i){
			for(int j=1;j<=cy;++j){
				int id=(i-1)*cy+j;
				num[id]=0;
				fa[id]=id;
				for(int k=1;k<=n;++k){
					int l=x[i-1],r=x[i],b=y[j-1],t=y[j];
					if(l>=a[k].l&&r<=a[k].r&&b>=a[k].b&&t<=a[k].t){
						num[id]+=(1ll)<<(k-1);
					}
				}
			}
		}
		for(int i=1;i<=cx;++i){
			for(int j=1;j<=cy;++j){
				int id=(i-1)*cy+j;
				if(j!=cy){
					int id2=id+1;
					if(num[id]==num[id2]){
						int xx=find(id),yy=find(id2);
						if(xx!=yy)fa[xx]=yy;
					}
				}
				if(i!=cx){
					int id2=id+cy;
					if(num[id]==num[id2]){
						int xx=find(id),yy=find(id2);
						if(xx!=yy)fa[xx]=yy;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=cx;++i){
			for(int j=1;j<=cy;++j){
				int id=(i-1)*cy+j;
				if(fa[id]==id)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
