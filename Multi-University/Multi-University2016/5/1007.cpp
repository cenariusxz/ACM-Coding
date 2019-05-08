#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll dp[20][6][100000];
int v[20][6][100000];
int low[6]={0,1,10,100,1000,10000};
int high[6]={0,9,99,999,9999,99999};

void Pre2(){
	for(int i=0;i<=99;++i){
		int vis[10]={0,0,0,0,0,0,0,0,0,0};
		int tmp=i;
		while(tmp){
			vis[tmp%10]++;
			tmp/=10;
		}
		for(int i=0;i<=9;++i){

		}
	}
	for(int i=1;i<=18;++i){
/*		for(int k=0;k<=9;++k){
			for(int p=0;p<=9;++p){
				if(p!=k){
					dp[i+1][2][p*10+k]+=dp[i][2][k];
					if(i+1==3&&p*10+k==21)printf("%d %d %d\n",i,2,k);
				}
			}
		}*/
		for(int k=1;k<=99;++k){
			int k1=k/10,k2=k%10;
			for(int p=0;p<=9;++p){
				if(p!=k1){
					dp[i+1][2][p*10+k1]+=dp[i][2][k];
				//	if(i+1==3&&p*10+k1==21)printf("%d %d %d\n",i,2,k);
				}
			}
		}
	}
	for(int i=1;i<=20;++i)printf("%d %lld\n",i,dp[2][2][i]);
}

void init(){
	memset(dp,0,sizeof(dp));
	memset(v,0,sizeof(v));
	Pre2();
}
/*
ll solve(ll a,int k){
	int t=0;
	ll tmp=a;
	int vis[10]={0,0,0,0,0,0,0,0,0,0};
	while(tmp){
		t++;
		vis[tmp%10]++;
		tmp/=10;
	}
	if(t<k)k=t;
	ll ans=0;
	for(int i=1;i<t;++i){
		for(int j=low[k];j<=high[k];++j)ans+=dfs(i,k,j);
	}
	if(a<=99999)return ans;
	tmp=a;
	while(tmp>99999){
		tmp/=10;
	}
	if(k>=4)tmp/=10;
	else if(k>=3)tmp/=100;
	else if(k>=2)tmp/=1000;
	for(int j=low[k];j<=high[j]&&j<)
}
*/
int main(){
	init();
	ll l,r;
	int k;
	while(scanf("%lld%lld%d",&l,&r,&k)!=EOF){
//		printf("%lld\n",solve(r,k)-solve(l-1,k));
	}
	return 0;
}
