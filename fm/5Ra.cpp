#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=50;

int st[maxn<<2],cov[maxn<<2],y[maxn];
int Q[maxn];

struct rect{
	int x1,y1,x2,y2;
}R[maxn];

struct seg{
	int x,y1,y2,c;
	bool operator < (const seg a)const{
		return x<a.x;
	}
}s[maxn];

inline void build(){
	memset(st,0,sizeof(st));
	memset(cov,0,sizeof(cov));
}

void pushup(int o,int l,int r){
	if(cov[o])st[o]=y[r]-y[l];
	else if(l+1==r)st[o]=0;
	else st[o]=st[o<<1]+st[o<<1|1];
}

void update(int o,int l,int r,seg a){
	if(a.y1<=y[l]&&a.y2>=y[r]){
		cov[o]+=a.c;
		pushup(o,l,r);
		return;
	}
	if(l+1==r)return;
	int m=l+((r-l)>>1);
	if(a.y1<y[m])update(o<<1,l,m,a);
	if(a.y2>y[m])update(o<<1|1,m,r,a);
	pushup(o,l,r);
}

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	int n,m,c=0;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		printf("Case %d:\n",++c);
		for(int i=1;i<=n;++i){
		//	scanf("%d%d%d%d",&R[i].x1,&R[i].y1,&R[i].x2,&R[i].y2);
			R[i].x1=read();
			R[i].y1=read();
			R[i].x2=read();
			R[i].y2=read();
		}
		build();
		for(int q=1;q<=m;++q){
			int k=read();
		//	scanf("%d",&k);
			int cnt=0;
			for(int i=1;i<=k;++i){
				int num=read();
			//	scanf("%d",&num);
				++cnt;
				s[cnt].x=R[num].x1;s[cnt].y1=R[num].y1;s[cnt].y2=R[num].y2;
				s[cnt].c=1;
				y[cnt]=R[num].y1;
				++cnt;
				s[cnt].x=R[num].x2;s[cnt].y1=R[num].y1;s[cnt].y2=R[num].y2;
				s[cnt].c=-1;
				y[cnt]=R[num].y2;
			}
			sort(y+1,y+cnt+1);
			int t=unique(y+1,y+cnt+1)-(y+1);
			sort(s+1,s+cnt+1);
			int sum=0;
			for(int j=1;j<cnt;++j){
				update(1,1,t,s[j]);
				sum+=st[1]*(s[j+1].x-s[j].x);
			}
			update(1,1,t,s[cnt]);
			printf("Query %d: %d\n",q,sum);
		}
		printf("\n");
	}
	return 0;
}
