#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=5e6+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

ll num[maxn];

int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=n;++i){
			scanf("%lld",&num[i]);
		}
		sort(num+1,num+n+1);
		ll ans=0;
		if(n==2){
			ans=max(a*num[1]*num[1]+b*num[2],a*num[2]*num[2]+b*num[1]);
		}
		else if(a>0&&b>0){
			if(num[1]*num[1]>=num[n]*num[n]){
				ans=a*num[1]*num[1]+b*num[n];
			}
			else{
				ll t1=a*num[1]*num[1]+b*num[n];
				ll t2=a*num[n-1]*num[n-1]+b*num[n];
				ll t3=a*num[n]*num[n]+b*num[n-1];
				ans=max(t1,max(t2,t3));
			}
		}
		else if(a>0&&b<=0){
			if(num[1]*num[1]>num[n]*num[n]){
				ll t1=a*num[1]*num[1]+b*num[2];
				ll t2=a*num[2]*num[2]+b*num[1];
				ll t3=a*num[n]*num[n]+b*num[1];
				ans=max(t1,max(t2,t3));
			}
			else{
				ans=a*num[n]*num[n]+b*num[1];
			}
		}
		else if(a<0&&b>=0){
			int p;
			ll minn=0x7fffffffffffffff;
			for(int i=1;i<=n;++i){
				if(num[i]*num[i]<minn){
					minn=num[i]*num[i];
					p=i;
				}
			}
			if(p==n){
				ll t1=a*num[n]*num[n]+b*num[n-1];
				ll t2=a*num[n-1]*num[n-1]+b*num[n];
				ans=max(t1,t2);
			}
			else{
				ans=a*minn+b*num[n];
			}
		}
		else if(a<0&&b<0){
			int p;
			ll minn=0x7fffffffffffffff;
			for(int i=1;i<=n;++i){
				if(num[i]*num[i]<minn){
					minn=num[i]*num[i];
					p=i;
				}
			}
			if(p==1){
				ll t1=a*num[1]*num[1]+b*num[2];
				ll t2=a*num[2]*num[2]+b*num[1];
				ans=max(t1,t2);
			}
			else{
				ans=a*minn+b*num[1];
			}
		}
		else if(a==0){
			if(b>=0)ans=b*num[n];
			else ans=b*num[1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
