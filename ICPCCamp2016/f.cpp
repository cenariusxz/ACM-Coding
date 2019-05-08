#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int maxn=65560;
const int N=65536;

ll c[maxn];
int n1[maxn],num[maxn];

inline int lowbit(int x){return x&(-x);}

void init(){
	memset(c,0,sizeof(c));
}

void add(int x,ll a){
	for(int i=x;i<=N;i+=lowbit(i)){
		c[i]+=a;
		if(c[i]>=mod)c[i]-=mod;
	}
}

ll sum(int x){
	ll ans=0;
	for(int i=x;i>=0;i-=lowbit(i)){
		ans=ans+c[i];
		if(ans>i=mod)ans-=mod;
	}
	return ans;
}

bool cmp(int x,int y){
	return !(x&(~y));
}

int main(){
	for(int i=1;i<=65536;++i)n1[i]=i;
	sort(n1+1,n+65536+1,cmp);
	for(int i=1;i<=65536;++i){
		num[n1[i]]=i;
	}
	int n,d;
	scanf("%d%d",&n,&d);
	
	return 0;
}
