#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double dp[2][51][51][51][51];
double ans[6];
int a[6];
int n,k;

void solve(){
	memset(dp,0,sizeof(dp));
	int num0=a[1]+a[2]+a[3]+a[4]+a[5];
	dp[num0&1][a[1]][a[2]][a[3]][a[4]]=1;
	for(int num=num0;num<k;++num){
		int now=num&1,nxt=now^1;
		memset(dp[nxt],0,sizeof(dp[nxt]));
		int lim1=a[1]+(num-num0);
		if(!a[1])lim1=0;
		for(int i1=a[1];i1<=lim1;++i1){
			int lim2=a[2]+(num-num0-(i1-a[1]));
			if(!a[2])lim2=0;
			for(int i2=a[2];i2<=lim2;++i2){
				int lim3=a[3]+(num-num0-(i1-a[1])-(i2-a[2]));
				if(!a[3])lim3=0;
				for(int i3=a[3];i3<=lim3;++i3){
					int lim4=a[4]+(num-num0-(i1-a[1])-(i2-a[2])-(i3-a[3]));
					if(!a[4])lim4=0;
					for(int i4=a[4];i4<=lim4;++i4){
						int i5=num-i1-i2-i3-i4;
						if(!a[5]&&i5>0)continue;
						dp[nxt][i1+1][i2][i3][i4]+=dp[now][i1][i2][i3][i4]*i1/num;
						dp[nxt][i1][i2+1][i3][i4]+=dp[now][i1][i2][i3][i4]*i2/num;
						dp[nxt][i1][i2][i3+1][i4]+=dp[now][i1][i2][i3][i4]*i3/num;
						dp[nxt][i1][i2][i3][i4+1]+=dp[now][i1][i2][i3][i4]*i4/num;
						dp[nxt][i1][i2][i3][i4]+=dp[now][i1][i2][i3][i4]*i5/num;

					}
				}
			}
		}
	}
	memset(ans,0,sizeof(ans));
	int num=k;
	int now=k&1;
	int lim1=a[1]+(num-num0);
	if(!a[1])lim1=a[1];
	for(int i1=a[1];i1<=lim1;++i1){
		int lim2=a[2]+(num-num0-(i1-a[1]));
		if(!a[2])lim2=0;
		for(int i2=a[2];i2<=lim2;++i2){
			int lim3=a[3]+(num-num0-(i1-a[1])-(i2-a[2]));
			if(!a[3])lim3=0;
			for(int i3=a[3];i3<=lim3;++i3){
				int lim4=a[4]+(num-num0-(i1-a[1])-(i2-a[2])-(i3-a[3]));
				if(!a[4])lim4=0;
				for(int i4=a[4];i4<=lim4;++i4){
					int i5=num-i1-i2-i3-i4;
					if(n<5&&i5>0)continue;
		//			printf("%d %d %d %d %d:%lf\n",i1,i2,i3,i4,i5,dp[now][i1][i2][i3][i4]);
					int maxx=max(i1,max(i2,max(i3,max(i4,i5))));
					int cnt=0;
					if(i1==maxx)cnt++;
					if(i2==maxx)cnt++;
					if(i3==maxx)cnt++;
					if(i4==maxx)cnt++;
					if(i5==maxx)cnt++;
					if(i1==maxx)ans[1]+=dp[now][i1][i2][i3][i4]/cnt;
					if(i2==maxx)ans[2]+=dp[now][i1][i2][i3][i4]/cnt;
					if(i3==maxx)ans[3]+=dp[now][i1][i2][i3][i4]/cnt;
					if(i4==maxx)ans[4]+=dp[now][i1][i2][i3][i4]/cnt;
					if(i5==maxx)ans[5]+=dp[now][i1][i2][i3][i4]/cnt;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)printf("pub %d: %.2lf %%\n",i,ans[i]*100);
}

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		k=read();
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)a[i]=read();
		if(n==1)printf("pub 1: 100.00 %%\n");
		else solve();
	}
	return 0;
}
