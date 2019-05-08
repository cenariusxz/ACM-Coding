#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxm=1e4+10;

struct seg{
	int y1,y2,x,c;
	bool operator<(const seg a)const{
		return x<a.x;
	}
}s[maxm];

int abs(int a){return a>0?a:-a;}

int st[maxm<<2],add[maxm<<2],num[maxm<<2],cov[maxm<<2];
bool ls[maxm<<2],rs[maxm<<2];
int y[maxm];

void pushup(int o,int l,int r){
	if(cov[o]>0){
		st[o]=y[r]-y[l];
		num[o]=1;
		ls[o]=rs[o]=1;
	}
	else if(l+1==r){
		st[o]=0;
		num[o]=0;
		ls[o]=rs[o]=0;	
	}
	else{
		st[o]=st[o<<1]+st[o<<1|1];
		ls[o]=ls[o<<1];
		rs[o]=rs[o<<1|1];
		num[o]=num[o<<1]+num[o<<1|1];
		if(rs[o<<1]&&ls[o<<1|1])num[o]--;
	}
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql<=y[l]&&qr>=y[r]){
		cov[o]+=c;
		pushup(o,l,r);
		return;
	}
	if(l+1==r)return;
	int m=l+((r-l)>>1);
	if(ql<y[m])update(o<<1,l,m,ql,qr,c);
	if(qr>y[m])update(o<<1|1,m,r,ql,qr,c);
	pushup(o,l,r);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int cnt=0;
		memset(st,0,sizeof(st));
		memset(add,0,sizeof(add));
		memset(num,0,sizeof(num));
		memset(ls,0,sizeof(ls));
		memset(rs,0,sizeof(rs));
		memset(cov,0,sizeof(cov));
		for(int i=1;i<=n;++i){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			s[2*i-1].y1=s[2*i].y1=y1;
			s[2*i-1].y2=s[2*i].y2=y2;
			s[2*i-1].x=x1;
			s[2*i].x=x2;
			s[2*i-1].c=1;
			s[2*i].c=-1;
			y[++cnt]=y1;
			y[++cnt]=y2;
		}
		sort(y+1,y+cnt+1);
		sort(s+1,s+2*n+1);
		cnt=1;
		for(int i=2;i<=2*n;++i){
			if(y[i]!=y[i-1])y[++cnt]=y[i];
		}
		int ans=0,p=0;
		for(int i=1;i<=2*n-1;++i){
			update(1,1,cnt,s[i].y1,s[i].y2,s[i].c);
			ans+=num[1]*2*(s[i+1].x-s[i].x);
			ans+=abs(st[1]-p);
			p=st[1];
		}
		update(1,1,cnt,s[2*n].y1,s[2*n].y2,s[2*n].c);
		ans+=abs(st[1]-p);
		printf("%d\n",ans);
	}
	return 0;
}
