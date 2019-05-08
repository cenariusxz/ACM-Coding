#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxm=1e6+5;

struct bea{
	int a,b;
	bool operator < (const bea x)const{
		return a<x.a;
	}
}b[maxn];

int c[maxm],l;
inline int lowbit(int x){return x&(-x);}

void add(int x){
	for(int i=x;i<=l;i+=lowbit(i))c[i]++;
}

int sum(int x){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
	return ans;
}

int dp[maxn];

int main(){
	int n;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	l=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&b[i].a,&b[i].b);
		b[i].a+=2;
		l=max(l,b[i].a);
	}
	sort(b+1,b+n+1);
	int ans=INF;
	dp[0]=0;
	dp[1]=0;
	ans=min(ans,n-1+dp[1]);
	add(b[1].a);
	for(int i=2;i<=n;++i){
		int q=max(2,b[i].a-b[i].b);
		int num=sum(b[i].a-1)-sum(q-1);
		dp[i]=dp[i-num-1]+num;
		ans=min(ans,n-i+dp[i]);
		add(b[i].a);
	}
	printf("%d\n",ans);
	return 0;
}
