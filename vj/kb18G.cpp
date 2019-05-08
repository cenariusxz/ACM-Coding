#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=2e5+5;
const int INF=0x3f3f3f3f;

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

char s[maxn];
int wa[maxn*3],wb[maxn*3],wv[maxn*3],wss[maxn*3];
int str[maxn*3],sa[maxn*3],Rank[maxn*3],height[maxn*3];
int n,k,len;
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

int st[maxn][32];
int prelog[maxn];

void initST(int n){
	prelog[1]=0;
	for(int i=2;i<=n;++i){
		prelog[i]=prelog[i-1];
		if((1<<prelog[i]+1)==i)++prelog[i];
	}
	for(int i=n-1;i>=0;--i){
		st[i][0]=i;
		for(int j=1;i+(1<<j)-1<n;++j){
			st[i][j]=Rank[st[i][j-1]]<=Rank[st[i+(1<<j-1)][j-1]]?st[i][j-1]:st[i+(1<<j-1)][j-1];
		}
	}
}

int queryST(int l,int r){
	int k=prelog[r-l+1];
	return Rank[st[l][k]]<=Rank[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}

void solve(){
	int ans=1,anslen=1,anspos=queryST(0,len-1);
	for(int i=1;i<=len;++i){
		int pos=0;
		while(pos+i<len){
			if(str[pos]!=str[pos+i]){
				pos+=i;
				continue;
			}
			int r=lcp(pos,pos+i),l=lcp(2*len-pos,2*len-(pos+i));
			int sum=l+r-1;
			int tmpans=sum/i+1;
			int tmplen=i,tmppos=queryST(pos-l+1,pos-l+sum-(tmpans-1)*i+1);
			if(tmpans>ans){
				ans=tmpans;
				anslen=tmplen;
				anspos=tmppos;
			}
			else if(tmpans==ans){
				if(Rank[tmppos]<Rank[anspos]){
					ans=tmpans;
					anslen=tmplen;
					anspos=tmppos;
				}
			}
			pos+=i;
		}
	}
	for(int i=0;i<anslen*ans;++i){
		printf("%c",s[anspos+i]);
	}
	printf("\n");
}

int main(){
	int cnt=0;
	while(scanf("%s",s)!=EOF&&s[0]!='#'){
		n=strlen(s);
		len=n;
		for(int i=0;i<n;++i)str[i]=s[i];
		str[n]='a'-1;
		for(int i=1;i<=n;++i)str[n+i]=s[n-i];
		str[n+n+1]=0;
		n=n*2+1;
		int minn=INF;
		for(int i=0;i<n;++i)if(str[i]<minn)minn=str[i];
		for(int i=0;i<n;++i)str[i]=str[i]-minn+1;
		int maxx=-INF;
		for(int i=0;i<n;++i)if(str[i]>maxx)maxx=str[i];
		maxx++;
		da(n,maxx);
		initRMQ(n);
		initST(n);
/*		for(int i=0;i<=n;++i)printf("%d ",str[i]);
		printf("\n");
		for(int i=0;i<=n;++i)printf("%d ",Rank[i]);
		printf("\n");
		for(int i=0;i<=n;++i)printf("%d ",sa[i]);
		printf("\n");
		for(int i=0;i<=n;++i)printf("%d ",height[i]);
		printf("\n");
*/
//		printf("%d %d\n",sa[1],str[sa[1]]);
		printf("Case %d: ",++cnt);
		solve();
	}
	return 0;
}
