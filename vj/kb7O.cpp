#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxm=2e3+5;
const double eps=1e-5;

struct seg{
	double x,y1,y2;
	int c;
	bool operator < (const seg a)const{
		return x<a.x;
	}
}s[maxm];

double y[maxm];
double st[maxm<<2],st2[maxm<<2];
int cov[maxm<<2];

void pushup(int o,int l,int r){
	if(cov[o]>1){
		st[o]=st2[o]=y[r]-y[l];
	}
	else if(cov[o]==1){
		st[o]=y[r]-y[l];
		if(l+1==r)st2[o]=0;
		else st2[o]=st[o<<1]+st[o<<1|1];
	}
	else{
		if(l+1==r)st[o]=st2[o]=0;
		else{
			st[o]=st[o<<1]+st[o<<1|1];
			st2[o]=st2[o<<1]+st2[o<<1|1];
		}
	}
}

void update(int o,int l,int r,seg a){
	if(y[l]>=a.y1&&y[r]<=a.y2){
		cov[o]+=a.c;
		pushup(o,l,r);
		return;
	}
	if(l+1==r)return;
	int m=l+((r-l)>>1);
	if(a.y1<=y[m])update(o<<1,l,m,a);
	if(a.y2>y[m])update(o<<1|1,m,r,a);
	pushup(o,l,r);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(st,0,sizeof(st));
		memset(cov,0,sizeof(cov));
		memset(st2,0,sizeof(st2));
		for(int i=1;i<=n;++i){
			double x1,y1,x2,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		/*	s[2*i-1].x=x1;
			s[2*i].x=x2;
			s[2*i-1].y1=y1;
			s[2*i].y1=y1;
			s[2*i-1].y2=y2;
			s[2*i].y2=y2;
			s[2*i-1].c=1;
			s[2*i].c=-1;
			y[2*i-1]=y1;
			y[2*i]=y2;*/
			s[2*i-1].x=x1;s[2*i-1].y1=y1;s[2*i-1].y2=y2;s[2*i-1].c=1;
			y[2*i-1]=y1;
			s[2*i].x=x2;s[2*i].y1=y1;s[2*i].y2=y2;s[2*i].c=-1;
			y[2*i]=y2;
		}
		sort(y+1,y+2*n+1);
		sort(s+1,s+2*n+1);
/*		int cnt=1;
		for(int i=2;i<=2*n;++i){
			if(y[i]!=y[i-1])y[++cnt]=y[i];
		}*/
		int cnt=2*n;
		double ans=0;
		update(1,1,cnt,s[1]);
		for(int i=2;i<=2*n;++i){
			ans+=st2[1]*(s[i].x-s[i-1].x);
			update(1,1,cnt,s[i]);
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
