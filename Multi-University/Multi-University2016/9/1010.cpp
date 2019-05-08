#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=2e5+5;
const int INF=0x3f3f3f3f;

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

char t[maxn];
int strt[maxn];

int wa[maxn*3],wb[maxn*3],wv[maxn*3],wss[maxn*3];
int str[maxn*3],sa[maxn*3],Rank[maxn*3],height[maxn*3];
int n,k;
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
	for(int i=0;i<=n;++i)Rank[sa[i]]=i;
	for(int i=0;i<n;++i){
		if(k)--k;
		j=sa[Rank[i]-1];
		while(str[i+k]==str[j+k])++k;
		height[Rank[i]]=k;
	}
}
int RMQ[maxn];
int mm[maxn];
int best[20][maxn];
void initRMQ(int n){
	for(int i=1;i<=n;++i)RMQ[i]=height[i];
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
	a=Rank[a];
	b=Rank[b];
	if(a>b)swap(a,b);
	return height[askRMQ(a+1,b)];
}

bool check(int mid){
	int stx=sa[mid];
	int i;
	for(i=0;str[stx+i]&&strt[i];++i){
		if(str[stx+i]>strt[i])return 1;
		else if(str[stx+i]<strt[i])return 0;
	}
	if(strt[i]==0)return 1;
	else return 0;
}

int minn;

void solve(){
	scanf("%s",t);
	int len=strlen(t);
	for(int i=0;i<=len-i-1;++i)swap(t[i],t[len-i-1]);
	for(int i=0;i<len;++i)strt[i]=t[i]-minn+1;
	strt[len]=0;
//	for(int i=0;i<=len;++i)printf("%d ",strt[i]);
//	printf("\n");
	int l=1,r=n;
	int posQ=INF;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(check(mid)){
			posQ=min(posQ,mid);
			r=mid-1;
		}
		else l=mid+1;
	}

	if(posQ==INF){printf("0\n");return;}
	int stx=sa[posQ];
	for(int i=0;i<len;++i)if(str[stx+i]!=strt[i]){
		printf("0\n");
		return;
	}



	int ans=1;
	int minn1,posl=posQ,posr=posQ;
	l=posQ+1,r=n;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(lcp(sa[posQ],sa[mid])>=len){
			posr=max(posr,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	l=1,r=posQ-1;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(lcp(sa[mid],sa[posQ])>=len){
			posl=min(posl,mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	if(posl==posr)minn1=len;
	else minn1=lcp(sa[posl],sa[posr]);
	int minn2=0;
	if(posr!=n)minn2=max(minn2,lcp(sa[posQ],sa[posr+1]));
	if(posl!=1)minn2=max(minn2,lcp(sa[posl-1],sa[posQ]));
//	printf("%d %d\n",minn1,minn2);
	ans=max(ans,minn1-minn2);
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int a,b;
		scanf("%d%d",&a,&b);
		n=0;
		int cnt=1;
		int len;
		while(a--){
			scanf("%s",t);
			len=strlen(t);
			for(int i=0;i<len;++i)str[n+i]=t[len-i-1];
			str[n+len]='a'-cnt;
			cnt++;
			n=n+len+1;
		}
		str[n]=0;
		minn=INF;
		for(int i=0;i<n;++i)if(str[i]<minn)minn=str[i];
		for(int i=0;i<n;++i)str[i]=str[i]-minn+1;
		int maxx=-INF;
		for(int i=0;i<n;++i)if(str[i]>maxx)maxx=str[i];
		maxx++;
		da(n,maxx);
		initRMQ(n);
/*		for(int i=0;i<=n;++i)printf("%d ",str[i]);
		printf("\n");
		for(int i=0;i<=n;++i)printf("%d ",Rank[i]);
		printf("\n");
		for(int i=0;i<=n;++i)printf("%d ",sa[i]);
		printf("\n");
		for(int i=0;i<=n;++i)printf("%d ",height[i]);
		printf("\n");
*/		printf("Case #%d:\n",q);
		while(b--)solve();
		 
	}
	return 0;
}
