#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int mod=1e8+73;

ll dp[5000];

int main(){
	 int a,b;
	 while(scanf("%d%d",&a,&b)!=EOF){
		b=b-a+1;
		int l=1,r=5000;
		int k=10000;
		while(l<=r){
			int mid=l+((r-l)>>1);
			if(mid*(mid+1)/2>=b){
				k=min(k,mid);
				r=mid-1;
			}
			else l=mid+1;
		}
		int sum=k*(k+1)/2-b;
		if(sum==0){
			printf("%d 1\n",k);
			continue;
		}
		else{
			l=1,r=1000;
			int K=10000;
			while(l<=r){
				int mid=l+((r-l)>>1);
				if(mid*(mid+1)/2>=sum){
					K=min(K,mid);
					r=mid-1;
				}
				else l=mid+1;
			}
			ll ans=0;
			for(int i=0;i<=K;++i){
				memset(dp,0,sizeof(dp));
				dp[0]=1;
				int tsum=sum-i*(i+1)/2;
				int lim=i;
				for(int j=i+1;j<=k;++j){
					for(int k=0;k<=lim;++k){
						for(int p=tsum;p>=k;--p){
							dp[p]+=dp[p-k];
							dp[p-k]%=mod;
						}
					}
					lim++;
				}
				ans=(ans+dp[tsum])%mod;
			}
			printf("%d %lld\n",k,ans);
		}
	 }
	 return 0;
}
