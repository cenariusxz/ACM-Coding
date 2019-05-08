#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=3e6+5;

int n,k,q;

int ans[maxn];
int st[maxn<<2];

void build(int o,int l,int r){
	if(l==r){
		st[o]=1;
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);build(o<<1|1,m+1,r);
	st[o]=st[o<<1]+st[o<<1|1];
}

void update(int o,int l,int r,int pos){
	if(l==r){
		st[o]=0;
		return;
	}
	int m=l+((r-l)>>1);
	if(pos<=m)update(o<<1,l,m,pos);
	else update(o<<1|1,m+1,r,pos);
	st[o]=st[o<<1]+st[o<<1|1];
}

int query(int o,int l,int r,int c){
	if(l==r)return l;
	int m=l+((r-l)>>1);
	if(c<=st[o<<1])return query(o<<1,l,m,c);
	else return query(o<<1|1,m+1,r,c-st[o<<1]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&q);
		build(1,1,n);
		int posl=1;
		int sum=n;
		while(1){
			int num=1+(sum-1)/k;
			for(int i=0;i<num&&posl+i<=n;++i){
				if(i==0)ans[posl+i]=1;
				else ans[posl+i]=ans[posl+i-1]+k-1;
			}
			for(int i=0;i<num&&posl+i<=n;++i){
				ans[posl+i]=query(1,1,n,ans[posl+i]);
				update(1,1,n,ans[posl+i]);
			}
			sum-=num;
			posl+=num;
			if(sum<=0)break;
		}
		while(q--){
			int a;
			scanf("%d",&a);
			printf("%d\n",ans[a]);
		}
	}
	return 0;
}
