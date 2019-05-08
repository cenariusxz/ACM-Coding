#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll dp[2][4005][4005];
int t[4005],p[4005];
int st[4005],sp[4005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		st[0]=sp[0]=0;
		for(int i=1;i<=n;++i)scanf("%d%d",&t[i],&p[i]);
		for(int i=1;i<=n;++i){
			st[i]=st[i-1]+t[i];
			sp[i]=sp[i-1]+p[i];
		}
		dp[0][1][1]=0;
		dp[1][1][1]=0;
		for(int i=2;i<=n;++i){
			for(int j=1;j<=i;++j){
				if(i==j){
					dp[0][i][j]=dp[1][i][j]=0;
				}
				else{
					
				}
			}
		}
	}
	return 0;
}
