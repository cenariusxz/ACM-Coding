#include <bits/stdc++.h>
#define MAXN 55
using namespace std;
const double eps = 1e-8;
int n,p;
int r[MAXN],q[MAXN][MAXN],pp[MAXN];
struct node{
	int l,r;
	bool in(int x){
		return (l<=x&&x<=r);
	}
}a[MAXN][MAXN];

bool cmp(const node& x,const node& y)
{
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}

int f(int x)
{
	int i,j;
	int y[MAXN];
	//if(x==10) for(i=1;i<=n;i++) printf("  %d\n",pp[i]);
	for(i=1;i<=n;i++){
		for(j=pp[i]+1;j<=p;j++){
			if(a[i][j].l>x){
				y[i]=j-1;
				return 0;
			}
			if(a[i][j].in(x)) break;
		}
		y[i]=j;
		if(j>p) return 0;
		//if(!a[i][j].in(x)) return 0;
	}
	memcpy(pp,y,sizeof(y));
	return 1;
}

void fuck()
{
	int i,j,x;
	memset(pp,0,sizeof(pp));
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++) scanf("%d",&r[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=p;j++){
			scanf("%d",&x);
			a[i][j].l=ceil(x/1.1/r[i]-eps);
			a[i][j].r=floor(x/0.9/r[i]+eps);
			//printf(" %d %d %d %d\n",i,j,a[i][j].l,a[i][j].r);
		}
		sort(a[i]+1,a[i]+p+1,cmp);
	}
	int ans=0;
	for(i=1;i<=1111111;i++){
		if(f(i)){
			ans++;i--;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}

