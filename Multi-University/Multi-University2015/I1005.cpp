#include<stdio.h>
#include<string.h>
const int maxm=1e5+5;
typedef long long ll;
int a[maxm];
int dis[maxm];

int main(){
	int n,d1,d2;
	while(scanf("%d%d%d",&n,&d1,&d2)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int f=0;
		ll num=0;
		ll ans=n;
		for(int i=2;i<=n;++i){
			dis[i]=a[i]-a[i-1];
			if(dis[i]==d1){
				if(f==0||f==1){
					num++;
					f=1;
				}
				else if(f==2){
					ans+=(1+num)*num/2;
					f=1;
					num=1;
				}
			}
			else if(dis[i]==d2){
				if(f==2||f==1){
					num++;
					f=2;
				}
				else if(f==0){
					ans+=(1+num)*num/2;
					f=2;
					num=1;
				}
			}
			else{
				ans+=(1+num)*num/2;
				f=0;
				num=0;
			}
		}
		ans+=(1+num)*num/2;
		printf("%lld\n",ans);
	}
	return 0;
}
