#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=5e5+5;

ll sum[2][maxn];
ll dp[2][maxn];	//0 xiang you 1 xiang zuo
char s[maxn];

int main(){
	int n,a,b,T;
	scanf("%d%d%d%d",&n,&a,&b,&T);
	scanf("%s",s);
	if(s[0]=='h')sum[0][0]=sum[1][0]=dp[0][0]=dp[1][0]=1;
	else sum[0][0]=sum[1][0]=dp[0][0]=dp[1][0]=b+1;
	int ans=0;
	if(dp[0][0]<=T){
		ans=1;
		int cnt=1;
		for(int i=1;i<n;++i){
			cnt++;
			if(i==1)sum[0][i]=a+1;
			else sum[0][i]=sum[0][i-1]+a+1;
			dp[0][i]=dp[0][i-1]+a+1;
			if(s[i]=='w'){
				dp[0][i]+=b;
				sum[0][i]+=b;
			}
			if(dp[0][i]<=T)ans=max(ans,cnt);
		}
		cnt=1;
		for(int i=n-1;i>=1;--i){
			cnt++;
			if(i==n-1)sum[1][i]=a+1;
			else sum[1][i]=sum[1][i+1]+a+1;
			dp[1][i]=dp[1][(i+1)%n]+a+1;
			if(s[i]=='w'){
				dp[1][i]+=b;
				sum[1][i]+=b;
			}
			if(dp[1][i]<=T)ans=max(ans,cnt);
		}
		int pos=n-1;
		for(int i=n-2;i>=1;--i){
			while(pos>=i+1){
				ll t=dp[0][i]+i*(ll)a+sum[1][pos];
				if(t<=T){
					ans=max(ans,i+1+(n-pos));
					pos--;
				}
				else break;
			}
		}
		pos=1;
		for(int i=2;i<=n-1;++i){
			while(pos<=i-1){
				ll t=dp[1][i]+(n-i)*(ll)a+sum[0][pos];
				if(t<=T){
					ans=max(ans,pos+1+(n-i));
					pos++;
				}
				else break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
