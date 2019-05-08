#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAXM=2000;

double y[MAXM+5];
int cover[(MAXM<<2)+5],add[(MAXM<<2)+5];

struct seg{
	double x,y1,y2;
	int c;
}s[MAXM+5];

bool cmp(seg a,seg b){
	return a.x<b.x;
}

void pushdown(int o,int l,int r){
	if(add[o]){
		add[o<<1]+=add[o];
		add[o<<1|1]+=add[o];
		cover[o<<1]+=add[o];
		cover[o<<1|1]+=add[o];
		add[o]=0;
	}
}

double query(int o,int l,int r){
	if(cover[o]>1){
		return y[r]-y[l];
	}
	if(l+1==r)return 0;
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	return query(o<<1,l,m)+query(o<<1|1,m,r);
}

void update(int o,int l,int r,seg a){
	if(y[l]==a.y1&&y[r]==a.y2){
		cover[o]+=a.c;
		add[o]+=a.c;
		return;
	}
	if(l+1==r)return;
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(a.y2<=y[m])update(o<<1,l,m,a);
	else if(a.y1>=y[m])update(o<<1|1,m,r,a);
	else{
		seg tmp=a;
		tmp.y2=y[m];
		update(o<<1,l,m,tmp);
		tmp=a;
		tmp.y1=y[m];
		update(o<<1|1,m,r,tmp);
	}
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			int n,m=0;
			scanf("%d",&n);
			int i;
			for(i=1;i<=n;i++){
				double x1,y1,x2,y2,t;
				scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
				if(y1>y2){t=y1;y1=y2;y2=t;}
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
			}
			sort(y+1,y+m+1);
			sort(s+1,s+m+1,cmp);
			memset(cover,0,sizeof(cover));
			memset(add,0,sizeof(add));
			double sum=0;
			for(i=1;i<m;i++){
				update(1,1,m,s[i]);
				sum+=query(1,1,m)*(s[i+1].x-s[i].x);
			}
			printf("%.2lf\n",(int)(sum*100+0.5)/100.0);
		}
	}
	return 0;
}
