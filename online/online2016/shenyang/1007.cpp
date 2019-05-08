#include<stdio.h>
#include<string.h>
typedef long long ll;

ll dp[20][10][2];
ll ans[20];
ll num;

void init(){
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=18;++i){
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=i;++j){
			if(j==1){
				for(int k=1;k<=9;++k){
					if(k%2)dp[j][k][0]=1;
					else dp[j][k][1]=1;
				}
			}
			else{
				for(int k=0;k<=9;++k){
					for(int prek=0;prek<=9;++prek){
						int num1=prek%2,num2=k%2;
						if(num1==num2){
							dp[j][k][0]+=dp[j-1][prek][1];
							dp[j][k][1]+=dp[j-1][prek][0];
						}
						else dp[j][k][num1]+=dp[j-1][prek][1];
					}
				}
			}
		}
		for(int j=0;j<=9;++j)ans[i]+=dp[i][j][1];
	}
//	printf("%lld %lld\n",ans[1],ans[2]);
}

int s[20];

ll Dp[20][10][2][2];

ll solve(ll num){
	int dig=0;
	ll tmp=num;
	while(tmp){
		tmp/=10;
		dig++;
	}
	tmp=num;
	ll res=0;
	for(int i=1;i<dig;++i)res+=ans[i];
	for(int i=dig;i>=1;--i){
		s[i]=tmp%10;
		tmp/=10;
	}
	memset(Dp,0,sizeof(Dp));
	for(int i=1;i<=s[1];++i){
		if(i==s[1]){
			if(i%2)Dp[1][i][0][1]=1;
			else Dp[1][i][1][1]=1;
		}
		else{
			if(i%2)Dp[1][i][0][0]=1;
			else Dp[1][i][1][0]=1;
		}
	}
	for(int i=1;i<dig;++i){
		for(int j=0;j<=9;++j){
			for(int k=0;k<=9;++k){
				int num1=j%2,num2=k%2;
				if(num1==num2){
					Dp[i+1][k][1][0]+=Dp[i][j][0][0];
					Dp[i+1][k][0][0]+=Dp[i][j][1][0];
				}
				else{
					if(num2)Dp[i+1][k][0][0]+=Dp[i][j][1][0];
					else Dp[i+1][k][1][0]+=Dp[i][j][1][0];
				}
				if(k<s[i+1]){
					if(num1==num2){
						Dp[i+1][k][1][0]+=Dp[i][j][0][1];
						Dp[i+1][k][0][0]+=Dp[i][j][1][1];
					}
					else{
						if(num2)Dp[i+1][k][0][0]+=Dp[i][j][1][1];
						else Dp[i+1][k][1][0]+=Dp[i][j][1][1];
					}
				}
				if(k==s[i+1]){
					if(num1==num2){
						Dp[i+1][k][1][1]+=Dp[i][j][0][1];
						Dp[i+1][k][0][1]+=Dp[i][j][1][1];
					}
					else{
						if(num2)Dp[i+1][k][0][1]+=Dp[i][j][1][1];
						else Dp[i+1][k][1][1]+=Dp[i][j][1][1];
					}
				}
			}
		}
	}
	for(int i=0;i<=9;++i){
		res+=Dp[dig][i][1][0];
		res+=Dp[dig][i][1][1];
	}
	return res;
}

int main(){
	init();
	ll l,r;
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%lld%lld",&l,&r);
		l--;
		ll ans1,ans2;
		if(l==0)ans1=0;
		else ans1=solve(l);
		ans2=solve(r);
		printf("Case #%d: %lld\n",q,ans2-ans1);
	}
	return 0;
}
