#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxm=100005;

ll st[maxm<<2],a[maxm];
bool ch[maxm<<2];
int ql,qr;

void build(int o,int l,int r){
	if(l==r){
		st[o]=a[l];
		if(st[o]==1)ch[o]=1;
		else ch[o]=0;
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o]=st[o<<1]+st[o<<1|1];
	ch[o]=ch[o<<1]&ch[o<<1|1];
}

void update(int o,int l,int r){
	if(ch[o]==1)return;
	if(l==r){
		st[o]=sqrt(st[o]*1.0);
		if(st[o]==1)ch[o]=1;
		else ch[o]=0;
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m);
	if(qr>=m+1)update(o<<1|1,m+1,r);
	st[o]=st[o<<1]+st[o<<1|1];
	ch[o]=ch[o<<1]&ch[o<<1|1];
}

ll query(int o,int l,int r){
	if(ql<=l&&qr>=r)return st[o];
	int m=l+((r-l)>>1);
	ll ans=0;
	if(ql<=m)ans+=query(o<<1,l,m);
	if(qr>=m+1)ans+=query(o<<1|1,m+1,r);
	return ans;
}

int main(){
	int n;
	int cnt=0;
	while(scanf("%d",&n)!=EOF){
		int i;
		for(i=1;i<=n;++i)scanf("%I64d",&a[i]);
		build(1,1,n);
		int m;
		scanf("%d",&m);
		printf("Case #%d:\n",++cnt);
		for(i=1;i<=m;++i){
			int f;
			scanf("%d%d%d",&f,&ql,&qr);
			if(ql>qr){
				int t=ql;ql=qr;qr=t;
			}
			if(f==1)printf("%I64d\n",query(1,1,n));
			else update(1,1,n);
		}
		printf("\n");
	}
	return 0;
}
