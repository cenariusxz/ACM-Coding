#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+5;

struct point{
	int x,y,c;
	bool operator < (const point a)const{
		return x<a.x;
	}
}p[maxn];

struct seg{
	int x,y1,y2;
	bool operator < (const seg a)const{
		return x<a.x;
	}
}s[maxn];

int st[maxn<<2];
int yy[maxn];

void update(int o,int l,int r,point a){
	if(l==r){st[o]+=a.c;return;}
	int m=l+((r-l)>>1);
	if(a.y<=yy[m])update(o<<1,l,m,a);
	else update(o<<1|1,m+1,r,a);
	st[o]=st[o<<1]+st[o<<1|1];
}

int query(int o,int l,int r,seg a){
	if(a.y1<=yy[l]&&a.y2>=yy[r])return st[o];
	int m=l+((r-l)>>1);
	int ans=0;
	if(a.y1<=yy[m])ans+=query(o<<1,l,m,a);
	if(a.y2>=yy[m+1])ans+=query(o<<1|1,m+1,r,a);
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(st,0,sizeof(st));
		int n;
		scanf("%d",&n);
		int cnt1=0,cnt2=0;
		int cnt=0;
		for(int i=1;i<=n;++i){
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2){
				if(y1>y2)swap(y1,y2);
				++cnt2;
				s[cnt2].x=x1;s[cnt2].y1=y1;s[cnt2].y2=y2;
				yy[++cnt]=y1;yy[++cnt]=y2;
			}
			else{
				if(x1>x2)swap(x1,x2);
				++cnt1;
				p[cnt1].x=x1;p[cnt1].y=y1;p[cnt1].c=1;
				++cnt1;
				p[cnt1].x=x2+1;p[cnt1].y=y1;p[cnt1].c=-1;
				yy[++cnt]=y1;
			}
		}
		n=1;
		sort(yy+1,yy+cnt+1);
		for(int i=2;i<=cnt;++i){
			if(yy[i]!=yy[i-1])yy[++n]=yy[i];
		}
		sort(p+1,p+cnt1+1);
		sort(s+1,s+cnt2+1);
		int pos1=1,pos2=1;
		ll ans=0;
		while(pos1<=cnt1&&pos2<=cnt2){
			if(p[pos1].x<=s[pos2].x){
				update(1,1,n,p[pos1]);
				pos1++;
			}
			else{
				ans+=query(1,1,n,s[pos2]);
				pos2++;
			}
		}
		for(pos2;pos2<=cnt2;++pos2)ans+=query(1,1,n,s[pos2]);
		printf("%lld\n",ans);
	}
	return 0;
}
