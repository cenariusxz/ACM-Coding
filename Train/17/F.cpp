#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxm=50005*8;
const int maxn=1e5+5;

ll st[maxn<<2];
int cov[maxn<<2];

struct seg{
	int x,y1,y2,c;
	bool operator < (const seg a)const{
		return x<a.x;
	}
}s[maxm];

void pushup(int o,int l,int r){
	if(cov[o])st[o]=r-l;
	else if(l+1==r)st[o]=0;
	else st[o]=st[o<<1]+st[o<<1|1];
}

void update(int o,int l,int r,seg a){
	if(a.y1<=l&&a.y2>=r){
		cov[o]+=a.c;
		pushup(o,l,r);
		return;
	}
	if(l+1==r)return;
	int m=l+((r-l)>>1);
	if(a.y1<m)update(o<<1,l,m,a);
	if(a.y2>m)update(o<<1|1,m,r,a);
	pushup(o,l,r);
}

void build(){
	memset(st,0,sizeof(st));
	memset(cov,0,sizeof(cov));
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int cnt=0;
		int minn=5000000,maxx=-1;
		for(int i=1;i<=n;++i){
			int x[5],y[5];
			for(int i=1;i<=4;++i){
				scanf("%d%d",&x[i],&y[i]);
				if(y[i]<minn)minn=y[i];
				if(y[i]>maxx)maxx=y[i];
			}
			++cnt;
			s[cnt].x=x[1],s[cnt].y1=y[1],s[cnt].y2=y[2],s[cnt].c=1;
			++cnt;
			s[cnt].x=x[3],s[cnt].y1=y[1],s[cnt].y2=y[2],s[cnt].c=-1;
			++cnt;
			s[cnt].x=x[3],s[cnt].y1=y[4],s[cnt].y2=y[2],s[cnt].c=1;
			++cnt;
			s[cnt].x=x[4],s[cnt].y1=y[4],s[cnt].y2=y[2],s[cnt].c=-1;
			++cnt;
			s[cnt].x=x[3],s[cnt].y1=y[1],s[cnt].y2=y[3],s[cnt].c=1;
			++cnt;
			s[cnt].x=x[4],s[cnt].y1=y[1],s[cnt].y2=y[3],s[cnt].c=-1;
			++cnt;
			s[cnt].x=x[4],s[cnt].y1=y[1],s[cnt].y2=y[2],s[cnt].c=1;
			++cnt;
			s[cnt].x=x[2],s[cnt].y1=y[1],s[cnt].y2=y[2],s[cnt].c=-1;
		}
		sort(s+1,s+cnt+1);
		ll sum=0;
		for(int i=1;i<cnt;++i){
			update(1,minn,maxx,s[i]);
			sum+=st[1]*(s[i+1].x-s[i].x);
		}
		update(1,minn,maxx,s[cnt]);
		printf("%lld\n",sum);
	}
	return 0;
}
