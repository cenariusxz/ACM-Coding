#include <stdio.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = maxn<<2;

int lmax[maxm],rmax[maxm],stmax[maxm],lmin[maxm],rmin[maxm],stmin[maxm],sum[maxm];
int num[maxn],n,m;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

inline int max(int a,int b,int c){
	return max(a,max(b,c));	
}

inline int min(int a,int b,int c){
	return min(a,min(b,c));	
}

void pushup(int o){
	lmax[o] = max(lmax[o<<1], sum[o<<1] + lmax[o<<1|1]);
	rmax[o] = max(rmax[o<<1|1], sum[o<<1|1] + rmax[o<<1]);
	stmax[o] = max(stmax[o<<1], stmax[o<<1|1], rmax[o<<1] + lmax[o<<1|1]);
	lmin[o] = min(lmin[o<<1], sum[o<<1] + lmin[o<<1|1]);
	rmin[o] = min(rmin[o<<1|1], sum[o<<1|1] + rmin[o<<1]);
	stmin[o] = min(stmin[o<<1], stmin[o<<1|1], rmin[o<<1] + lmin[o<<1|1]);
	sum[o] = sum[o<<1] + sum[o<<1|1];
}

void build(int o,int l,int r){
	if(l == r){
		lmax[o] = rmax[o] = stmax[o] = lmin[o] = rmin[o] = stmin[o] = sum[o] = num[l];
		return;
	}
	int m = (l+r)>>1;
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	pushup(o);
}

void update(int o,int l,int r,int ind,int c){
	if(l == r){
		lmax[o] = rmax[o] = stmax[o] = lmin[o] = rmin[o] = stmin[o] = sum[o] = c;
		return;
	}
	int m = (l+r)>>1;
	if(ind <= m)update(o<<1,l,m,ind,c);
	else update(o<<1|1,m+1,r,ind,c);
	pushup(o);
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--){
		int ind,c;
		scanf("%d%d",&ind,&c);
		update(1,1,n,ind,c);
		int ans = max(stmax[1], sum[1] - stmin[1]);
		if(ans == sum[1])ans = sum[1] - stmin[1];
		printf("%d\n",ans);	
	}
	return 0;
}

