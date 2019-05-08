#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int wa[maxn*3],wb[maxn*3],wv[maxn*3],wss[maxn*3];
char s[maxn];
char mo[5];
int str[maxn*3],sa[maxn*3],rank[maxn*3],height[maxn*3];
int n,k;
int su[maxn];
int c0(int *r,int a,int b){
	return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k,int *r,int a,int b){
	if(k==2)return r[a]<r[b]||(r[a]==r[b]&&c12(1,r,a+1,b+1));
	else return r[a]<r[b]||(r[a]==r[b]&&wv[a+1]<wv[b+1]);
}
void sort(int *r,int *a,int *b,int n,int m){
	for(int i=0;i<n;++i)wv[i]=r[a[i]];
	for(int i=0;i<m;++i)wss[i]=0;
	for(int i=0;i<n;++i)wss[wv[i]]++;
	for(int i=1;i<m;++i)wss[i]+=wss[i-1];
	for(int i=n-1;i>=0;--i)b[--wss[wv[i]]]=a[i];
}
void dc3(int *r,int *sa,int n,int m){
	int i,j,*rn=r+n;
	int *san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
	r[n]=r[n+1]=0;
	for(i=0;i<n;++i)if(i%3)wa[tbc++]=i;
	sort(r+2,wa,wb,tbc,m);
	sort(r+1,wb,wa,tbc,m);
	sort(r,wa,wb,tbc,m);
	for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;++i)rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
	if(p<tbc)dc3(rn,san,tbc,p);
	else for(i=0;i<tbc;++i)san[rn[i]]=i;
	for(i=0;i<tbc;++i)if(san[i]<tb)wb[ta++]=san[i]*3;
	if(n%3==1)wb[ta++]=n-1;
	sort(r,wb,wa,ta,m);
	for(i=0;i<tbc;++i)wv[wb[i]=G(san[i])]=i;
	for(i=0,j=0,p=0;i<ta&&j<tbc;++p)sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
	for(;i<ta;++p)sa[p]=wa[i++];
	for(;j<tbc;++p)sa[p]=wb[j++];
}
void da(int n,int m){
	for(int i=n;i<n*3;++i)str[i]=0;
	dc3(str,sa,n+1,m);
	int i,j,k=0;
	for(int i=0;i<=n;++i)rank[sa[i]]=i;
	for(int i=0;i<n;++i){
		if(k)--k;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])++k;
		height[rank[i]]=k;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%s%s",mo,s);
		n=strlen(s);
		for(int i=0;i<n;++i)str[i]=s[i];
		int minn=INF;
		for(int i=0;i<n;++i)if(str[i]<minn)minn=str[i];
		for(int i=0;i<n;++i)str[i]=str[i]-minn+1;
		int Mo=mo[0]-minn+1;
		int maxx=-INF;
		for(int i=0;i<n;++i)if(str[i]>maxx)maxx=str[i];
		maxx++;
		da(n,maxx);
		memset(su,-1,sizeof(su));
		for(int i=n-1;i>=0;--i){
			if(str[i]==Mo)su[i]=i;
			else su[i]=su[i+1];
		}
		ll ans=0;
		for(int i=1;i<=n;++i){
			ll a1=n-sa[i]-height[i];
			ll a2;
			if(su[sa[i]]==-1)continue;
			else a2=n-su[sa[i]];
			ans+=min(a1,a2);
		}
		printf("Case #%d: %lld\n",q,ans);
	}
	return 0;
}
