#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxm=2010;
typedef long long ll;

ll st1[maxm<<2],st2[maxm<<2],st3[maxm<<2];
int cov[maxm<<2],y[maxm],z[maxm];

struct rect{
	int x1,y1,z1,x2,y2,z2;
}r[1005];

struct seg{
	int x,y1,y2,c;
	bool operator < (const seg a)const{
		return x<a.x;
	}
}s[maxm];

void pushup(int o,int l,int r){
	if(cov[o]>=3)st1[o]=st2[o]=st3[o]=y[r]-y[l];
	else if(cov[o]==2){
		st1[o]=st2[o]=y[r]-y[l];
		if(l+1==r)st3[o]=0;
		else st3[o]=st1[o<<1]+st1[o<<1|1];
	}
	else if(cov[o]==1){
		st1[o]=y[r]-y[l];
		if(l+1==r)st2[o]=st3[o]=0;
		else{
			st2[o]=st1[o<<1]+st1[o<<1|1];
			st3[o]=st2[o<<1]+st2[o<<1|1];
		}
	}
	else{
		if(l+1==r)st1[o]=st2[o]=st3[o]=0;
		else{
			st1[o]=st1[o<<1]+st1[o<<1|1];
			st2[o]=st2[o<<1]+st2[o<<1|1];
			st3[o]=st3[o<<1]+st3[o<<1|1];
		}
	}
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

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].z1,&r[i].x2,&r[i].y2,&r[i].z2);
			y[2*i-1]=r[i].y1;
			y[2*i]=r[i].y2;
			z[2*i-1]=r[i].z1;
			z[2*i]=r[i].z2;
		}
		sort(y+1,y+2*n+1);
		sort(z+1,z+2*n+1);
		int cntz=1,cnty=1;
		ll ans=0;
		for(int i=2;i<=2*n;++i){
			if(y[i]!=y[i-1])y[++cnty]=y[i];
			if(z[i]!=z[i-1])z[++cntz]=z[i];
		}
		for(int i=1;i<cntz;++i){
			int cnt=0;
			for(int j=1;j<=n;++j){
				if(r[j].z1<=z[i]&&r[j].z2>z[i]){
					++cnt;
					s[cnt].x=r[j].x1;s[cnt].y1=r[j].y1;s[cnt].y2=r[j].y2;
					s[cnt].c=1;
					++cnt;
					s[cnt].x=r[j].x2;s[cnt].y1=r[j].y1;s[cnt].y2=r[j].y2;
					s[cnt].c=-1;
				}
			}
			sort(s+1,s+cnt+1);
			ll sum=0;
			for(int j=1;j<cnt;++j){
				update(1,1,cnty,s[j]);
				sum+=st3[1]*(s[j+1].x-s[j].x);
			}
			update(1,1,cnty,s[cnt]);
			ans+=sum*(z[i+1]-z[i]);
		}
		printf("Case %d: %lld\n",q,ans);
	}
	return 0;
}
