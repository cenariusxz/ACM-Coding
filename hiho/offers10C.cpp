#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int INF=0x3f3f3f3f;

int a[maxn];
int b[maxn];
int Min[maxn];
map<int,int>M;
map<ll,ll>M1;
map<ll,ll>::iterator it;

void init(int n){
	int cnt=0;
	map<int,int>M2;
	for(int i=1;i<=n;++i){
		if(M2[a[i]])a[i]=M2[a[i]];
		else{
			M2[a[i]]=++cnt;
			a[i]=cnt;
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		ll k;
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		init(n);
		
/*		M.clear();
		memset(Min,0x3f,sizeof(Min));
		for(int i=n;i>=1;--i){
			if(M[a[i]])Min[i]=M[a[i]];
			else Min[i]=n+1;
			M[a[i]]=i;
		}
		for(int i=n;i>=1;--i){
			Min[i]=min(Min[i],Min[i+1]);
		}
		ll sum=0;
		for(int i=1;i<=n;++i){
//			printf("%d ",Min[i]);
			sum+=Min[i]-1-i+1;
		}
//		printf("\n");
		if(k<=sum){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;++i){
			if(Min[i]!=n+1){
				sum+=Min[i+1]-1-Min[i]+1;
			}
		}
		if(k<=sum){
			printf("1\n");
			continue;
		}

*/
		M1.clear();
		ll ans=0;
		for(int i=1;i<=n;++i){
			M.clear();
			ll tmp=0;
			for(int j=i;j<=n;++j){
				tmp+=M[a[j]];
				M1[tmp]++;
				M[a[j]]++;
			}
		}
		
		for(it = M1.begin();it!=M1.end();it++){
			ans+=(*it).second;
			if(ans>=k){
				printf("%lld\n",(*it).first);
				break;
			}
		}
	}
	return 0;
}
