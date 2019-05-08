#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int a[105];
int vis[100005];
int pri[105];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		bool f=0;
		int c=0;
		int mi=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1)continue;
			int cnt=0;
			for(ll j=2;j*j<=a[i];++j){
				if(!(a[i]%j)){
					vis[j]++;
					a[i]/=j;
					j--;
					cnt++;
				}
				if(cnt==2)break;
			}
			if(cnt<2&&a[i]>1){
				if(a[i]<100004)vis[a[i]]++;
				else pri[++c]=a[i];
			}
		}
		int cnt=0;
		ll ans=1;
		for(int i=1;i<=100004&&cnt<2;++i){
			if(vis[i]){
				if(cnt==0&&vis[i]>1){
					ans=ans*i*i;
					cnt+=2;
				}
				else{
					ans=ans*i;
					cnt++;
				}
			}
		}
		sort(pri+1,pri+c+1);
		if(cnt==0&&c>=2){
			ans=ans*pri[1]*pri[2];
			cnt=2;
		}
		else if(cnt==1&&c>=1){
			ans=ans*pri[1];
			cnt=2;
		}
		if(cnt<2)printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
