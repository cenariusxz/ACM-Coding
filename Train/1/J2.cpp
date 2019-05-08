#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll INFF=1ll<<62;
const int mod=1e9+7;
const int maxn=5e5+5;

ll sum[maxn],MIN[maxn],add[maxn];
int pos[maxn],a[maxn];
int P,n;
ll M;

void build(){
	memset(MIN,0,sizeof(MIN));
	memset(add,0,sizeof(add));
	for(int i=1;i<=n;++i){
		pos[i]=i;
	}
}

void pushdown(int o){
	if(add[o]){
		add[o<<1]+=add[o];
		add[o<<1|1]+=add[o];
		MIN[o<<1]+=add[o];
		MIN[o<<1|1]+=add[o];
		add[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,ll c){
	if(ql<=l&&qr>=r){
		add[o]+=c;
		MIN[o]+=c;
		return;
	}
	pushdown(o);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	if(MIN[o<<1]<MIN[o<<1|1]){
		pos[o]=pos[o<<1];
		MIN[o]=MIN[o<<1];
	}
	else{
	  	pos[o]=pos[o<<1|1];
		MIN[o]=MIN[o<<1|1];
	}
}

void query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		if(MIN[o]<M){
			M = MIN[o];
			P=pos[o];
		}
		return;
	}
	pushdown(o);
	int m=l+((r-l)>>1);
	if(ql<=m)query(o<<1,l,m,ql,qr);
	if(qr>=m+1)query(o<<1|1,m+1,r,ql,qr);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d%d",&n,&x);
		build();
		int ans=INF;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]>=x)ans=1;
		}
		if(ans==1){
			printf("1\n");
			continue;
		}
		int pre=1;
		ll s=0;
		for(int i=1;i<=n;++i){
			s+=a[i];
			if(s<=0){
				pre=i+1;
				s=0;
				continue;
			}
			update(1,1,n,i,i,s);
			while(s>=x){
				ans=min(ans,i-pre+1);
				M=INFF;P=0;
				query(1,1,n,pre,i);
				pre=P+1;
				s-=M;
				update(1,1,n,pre,i,-M);
			}
		}
		if(ans==INF)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
