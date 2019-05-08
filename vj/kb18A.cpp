#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int maxn=8e4+5;

int str[maxn],a[maxn],sa[maxn],rank[maxn],height[maxn];
int n;
int t1[maxn],t2[maxn],c[maxn];
/*
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int m){
	++n;
	int p,*x=t1,*y=t2;
	for(int i=0;i<m;++i)c[i]=0;
	for(int i=0;i<n;++i)c[x[i]=str[i]]++;
	for(int i=1;i<m;++i)c[i]+=c[i-1];
	for(int i=n-1;i>=0;--i)sa[--c[x[i]]]=i;
	for(int j=1;j<=n;j<<=1){
		p=0;
		for(int i=n-j;i<n;++i)y[p++]=i;
		for(int i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(int i=0;i<m;++i)c[i]=0;
		for(int i=0;i<n;++i)c[x[y[i]]]++;
		for(int i=1;i<m;++i)c[i]+=c[i-1];
		for(int i=n-1;i>=0;--i)sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for(int i=1;i<n;++i)x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p>=n)break;
		m=p;
	}
	int k=0;
	--n;
	for(int i=0;i<=n;++i)rank[sa[i]]=i;
	for(int i=0;i<n;++i){
		if(k)--k;
		int j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])++k;
		height[rank[i]]=k;
	}
}*/


#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int wa[maxn*3],wb[maxn*3],wv[maxn*3],wss[maxn*3];
//int str[maxn*3],sa[maxn*3],rank[maxn*3],height[maxn*3];
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
void da(int m){
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

int RMQ[maxn];
int mm[maxn];
int best[20][maxn];
void initRMQ(int n){
	mm[0]=-1;
	for(int i=1;i<=n;++i)mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
	for(int i=1;i<=n;++i)best[0][i]=i;
	for(int i=1;i<=mm[n];++i){
		for(int j=1;j+(1<<i)-1<=n;++j){
			int a=best[i-1][j];
			int b=best[i-1][j+(1<<(i-1))];
			if(RMQ[a]<RMQ[b])best[i][j]=a;
			else best[i][j]=b;
		}
	}
}
int askRMQ(int a,int b){
	int t;
	t=mm[b-a+1];
	b-=(1<<t)-1;
	a=best[t][a];
	b=best[t][b];
	return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b){
	a=rank[a];
	b=rank[b];
	if(a>b)swap(a,b);
	return height[askRMQ(a+1,b)];
}
int r[maxn];

bool check(int k){
	int minn=sa[1];
	int maxx=sa[1];
	for(int i=2;i<=n;++i){
		if(height[i]>=k){
			if(sa[i]>maxx)maxx=sa[i];
			if(sa[i]<minn)minn=sa[i];
		}
		else{
			if(maxx-minn>=k+1)return 1;
			minn=sa[i];
			maxx=sa[i];
		}
	}
	if(maxx-minn>=k+1)return 1;
	return 0;
}

int main(){
	while(scanf("%d",&n)!=EOF&&n){
		memset(str,0,sizeof(str));
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		int minn=0x3f3f3f3f;
		for(int i=0;i<n-1;++i)str[i]=a[i+1]-a[i];
		n--;
		for(int i=0;i<n;++i)if(str[i]<minn)minn=str[i];
		int maxx=-0x3f3f3f3f;
		for(int i=0;i<n;++i)str[i]=str[i]-minn+1;
		for(int i=0;i<n;++i)if(str[i]>maxx)maxx=str[i];
//		for(int i=0;i<n;++i)printf("%d ",str[i]);
//		printf("\n");
		maxx++;
		da(maxx);
//		for(int i=0;i<=n;++i)printf("%d ",rank[i]);
//		printf("\n");
//		for(int i=0;i<=n;++i)printf("%d ",sa[i]);
//		printf("\n");
//		for(int i=0;i<=n;++i)printf("%d ",height[i]);
//		printf("\n");
//		initRMQ(n);
		int left=4,right=n/2;
		int mid;
		int ans=0;
		while(left<=right){
			mid=(left+right)>>1;
			if(check(mid)){
				if(mid+1>ans)ans=mid+1;
				left=mid+1;
			}
			else right=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
