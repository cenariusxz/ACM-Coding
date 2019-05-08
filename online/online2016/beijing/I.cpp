#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

int st[maxn<<2],add[maxn<<2];
int ta,tb,x,n,m;
int sl[maxn],sr[maxn],sd[maxn],cnt2;
int y[maxn],cnt1;

void init(){
	cnt1=0;
	cnt2=0;
}

void build(){
	memset(st,0,sizeof(st));
	memset(add,0,sizeof(add));
}

void pushdown(int o){
	if(add[o]){
		add[o<<1]+=add[o];
		add[o<<1|1]+=add[o];
		st[o<<1]+=add[o];
		st[o<<1|1]+=add[o];
		add[o]=0;
	}
}

void update(int o,int l,int r,int id){
	if(sl[id]<=y[l]&&sr[id]>=y[r]){
		add[o]+=sd[id];
		st[o]+=sd[id];
		return;
	}
	int m=l+((r-l)>>1);
	pushdown(o);
	if(sl[id]<=y[m])update(o<<1,l,m,id);
	if(sr[id]>=y[m+1])update(o<<1|1,m+1,r,id);
	st[o]=max(st[o<<1],st[o<<1|1]);
}

int main(){
	while(scanf("%d%d",&ta,&tb)!=EOF){
		init();
		scanf("%d%d%d",&x,&n,&m);
		int a,b,c;
		int ans=0;
		int sum=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a,&b,&c);
			sum+=c;
			if(a+b<x||a+b>x+tb)ans+=c;
			else{
				int d=((x+tb)-(a+b))/b;
				if(d%2==0)d++;
				int l=a+b+b,r=a+b+b*d;
				if(l+ta>=r){
					int L=max(0,r-ta);
					++cnt2;sl[cnt2]=L;sr[cnt2]=l;sd[cnt2]=c;
					y[++cnt1]=L;y[++cnt1]=l;
				}
			}
		}
		for(int i=1;i<=m;++i){
			scanf("%d%d%d",&a,&b,&c);
			sum+=c;
			if(a+b+b<x||a+b+b>x+tb){
				int L=max(0,a+b-ta);
				++cnt2;sl[cnt2]=L;sr[cnt2]=a+b;sd[cnt2]=c;
				y[++cnt1]=L;y[++cnt1]=a+b;
			}
			else{
				int d=(x+tb-a)/b;
				if(d%2==0)d++;
				int l=a+b,r=a+b*d;
				if(l+ta>=r){
					int L=max(0,r-ta);
					++cnt2;sl[cnt2]=L;sr[cnt2]=l;sd[cnt2]=c;
					y[++cnt1]=L;y[++cnt1]=l;
				}
			}
		}
		sort(y+1,y+cnt1+1);
		c=1;
		for(int i=2;i<=cnt1;++i){
			if(y[i]!=y[i-1])y[++c]=y[i];
		}
		build();
		for(int i=1;i<=cnt2;++i){
			update(1,1,c,i);
		}
		printf("%d\n",sum-ans-st[1]);
	}
	return 0;
}
