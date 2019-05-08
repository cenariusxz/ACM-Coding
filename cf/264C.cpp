#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define mp make_pair
#define fi first
#define se second
const int maxn=1e5+5;
const ll INF=1ll<<60;

int n,q;
int v[maxn],c[maxn];
ll dp[maxn];
inline ll max(ll a,ll b){return a>b?a:b;}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	while(q--){
		ll A,B,ans=0;
		scanf("%I64d%I64d",&A,&B);
		pii m1(0,-INF),m2(0,-INF);
		for(int i=1;i<=n;++i)dp[i]=-INF;
		for(int i=1;i<=n;++i){
			ll tmp;
			if(c[i]!=m1.fi)tmp=m1.se;
			else tmp=m2.se;
			ll num=max(B*v[i],max(dp[c[i]]+A*v[i],tmp+B*v[i]));
			ans=max(ans,num);
			if(num>dp[c[i]]){
				dp[c[i]]=num;
				if(num>m1.se){
					if(c[i]==m1.fi)m1.se=num;
					else if(c[i]==m2.fi){m2.se=num;swap(m1,m2);}
					else{
						swap(m1,m2);
						m1.se=num;m1.fi=c[i];
					}
				}
				else if(num>m2.se&&c[i]!=m1.fi){
					m2.se=num;m2.fi=c[i];
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
