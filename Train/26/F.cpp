#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=250005;
const int INF=0x3f3f3f3f;

int n,m,R,Q,c1,c2;
int a1[505][505],a2[505][505];
int s1[505][505],s2[505][505];

struct FF{
	int f,p,d;
	bool operator<(const FF a)const{
		return d<a.d;
	}
}f[maxn];
struct PP{
	int f,p,d;
	bool operator<(const PP a)const{
		return d<a.d;
	}
}p[maxn];

int st[4][maxn<<2];

void build(int o,int l,int r,int x){
	if(l>r)return;
	if(l==r){
		if(x==0)st[x][o]=f[l].f;
		if(x==1)st[x][o]=f[l].p;
		if(x==2)st[x][o]=p[l].f;
		if(x==3)st[x][o]=p[l].p;
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m,x);
	build(o<<1|1,m+1,r,x);
	st[x][o]=max(st[x][o<<1],st[x][o<<1|1]);
}

int query(int o,int l,int r,int ql,int qr,int x){
	if(l>r||ql>qr)return -INF;
	if(ql<=l&&qr>=r){
		return st[x][o];
	}
	int m=l+((r-l)>>1);
	int ans=-1;
	if(ql<=m)ans=max(ans,query(o<<1,l,m,ql,qr,x));
	if(qr>=m+1)ans=max(ans,query(o<<1|1,m+1,r,ql,qr,x));
	return ans;
}

void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	int ans=-INF;
	if(b>=a){
		int rr=-1;
		int check=b-a;
		int l=1,r=c1;
		while(l<=r){
			int m=l+((r-l)>>1);
			if(f[m].d<=check){
				rr=max(rr,m);
				l=m+1;
			}
			else r=m-1;
		}
		ans=max(ans,query(1,1,c1,1,rr,0)+a);
		ans=max(ans,query(1,1,c1,rr+1,c1,1)+b);
		ans=max(ans,query(1,1,c2,1,c2,2)+a);
	}
	else{
		int rr=-1;
		int check=a-b;
		int l=1,r=c2;
		while(l<=r){
			int m=l+((r-l)>>1);
			if(p[m].d<=check){
				rr=max(rr,m);
				l=m+1;
			}
			else r=m-1;
		}
		ans=max(ans,query(1,1,c1,1,c1,1)+b);
		ans=max(ans,query(1,1,c2,1,rr,3)+b);
		ans=max(ans,query(1,1,c2,rr+1,c2,2)+a);
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		c1=0;c2=0;
		if(q!=1)printf("\n");
		scanf("%d%d%d%d",&n,&m,&R,&Q);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)scanf("%d",&a1[i][j]);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)scanf("%d",&a2[i][j]);
		}
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				s1[i][j]=s1[i][j-1]+a1[i][j];
				s2[i][j]=s2[i][j-1]+a2[i][j];
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				s1[i][j]+=s1[i-1][j];
				s2[i][j]+=s2[i-1][j];
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int a=max(0,i-R),b=min(n,i+R);
				int c=max(0,j-R),d=min(m,j+R);
				int F=s1[b][d]-s1[b][c-1]-s1[a-1][d]+s1[a-1][c-1];
				int P=s2[b][d]-s2[b][c-1]-s2[a-1][d]+s2[a-1][c-1];
				if(F>=P){
					++c1;f[c1].f=F;f[c1].p=P;f[c1].d=F-P;
				}
				else{
					++c2;p[c2].f=F;p[c2].p=P;p[c2].d=P-F;
				}
			}
		}
		sort(f+1,f+c1+1);sort(p+1,p+c2+1);
		build(1,1,c1,0);build(1,1,c1,1);
		build(1,1,c2,2);build(1,1,c2,3);
		printf("Case #%d:\n",q);
		while(Q--)solve();
	}
	return 0;
}
