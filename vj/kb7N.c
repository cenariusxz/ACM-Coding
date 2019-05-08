#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define INF 0x3F3F3F3F
const int MAXM=10000;

struct seg{
	int x,y1,y2,c;
}s[MAXM+5];

int y[MAXM+5],cover[(MAXM<<2)+5],num[(MAXM<<2)+5],segtree[(MAXM<<2)+5];
bool yl[(MAXM<<2)+5],yr[(MAXM<<2)+5];
bool cmp(seg a,seg b){
	return a.x<b.x;
}

void update(int o,int l,int r,seg a){
	int m=l+((r-l)>>1);
	if(y[l]==a.y1&&y[r]==a.y2){
		cover[o]+=a.c;
	}
	else{
		if(a.y2<=y[m]||a.y1>=y[m]){
			if(a.y2<=y[m])update(o<<1,l,m,a);
			if(a.y1>=y[m])update(o<<1|1,m,r,a);
		}
		else{
			seg tmp=a;
			tmp.y2=y[m];
			update(o<<1,l,m,tmp);
			tmp=a;
			tmp.y1=y[m];
			update(o<<1|1,m,r,tmp);
		}
	}
	if(cover[o]>0){
		yl[o]=yr[o]=1;
		num[o]=1;
		segtree[o]=y[r]-y[l];
	}
	else if(l+1<r){
		segtree[o]=segtree[o<<1]+segtree[o<<1|1];
		yl[o]=yl[o<<1];
		yr[o]=yr[o<<1|1];
		num[o]=num[o<<1]+num[o<<1|1]-yr[o<<1]*yl[o<<1|1];
	}
	else{
		segtree[o]=0;
		yl[o]=yr[o]=0;
		num[o]=0;
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int x1,y1,x2,y2;
		int i,m=0,xx=INF,yy=INF;
		for(i=1;i<=n;i++){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			s[++m].x=x1;
			s[m].y1=y1;
			s[m].y2=y2;
			s[m].c=1;
			y[m]=y1;
			s[++m].x=x2;
			s[m].y1=y1;
			s[m].y2=y2;
			s[m].c=-1;
			y[m]=y2;
			if(x1<xx)xx=x1;
			if(y1<yy)yy=y1;
		}
		for(i=1;i<=m;i++){
			s[i].x-=xx;
			s[i].y1-=yy;
			s[i].y2-=yy;
			y[i]-=yy;
		}
		memset(num,0,sizeof(num));
		memset(yl,0,sizeof(yl));
		memset(yr,0,sizeof(yr));
		memset(cover,0,sizeof(cover));
		sort(y+1,y+m+1);
		sort(s+1,s+m+1,cmp);
		int cnt=0;
		for(i=2;i<=m;i++){
			if(y[i]!=y[i-1]){
				y[++cnt]=y[i-1];
			}
		}
		if(y[m]!=y[cnt])y[++cnt]=y[m];/*
		printf("AAA\n");
		for(i=1;i<=m;i++){
			printf("%d ",y[i]);
		}
		printf("\n");*/
		int ans=0;
		int llen=0;
		for(i=1;i<m;i++){
			update(1,1,cnt,s[i]);
			ans+=num[1]*2*(s[i+1].x-s[i].x);
			ans+=abs(segtree[1]-llen);
			llen=segtree[1];
		}
		update(1,1,cnt,s[i]);
		ans+=abs(segtree[1]-llen);
		printf("%d\n",ans);
	}
	return 0;
}
