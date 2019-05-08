#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

char s[20];
int dp[20][300000];
int q[2][300000][20],cnt[2][300000];

void init(){
	memset(cnt,0,sizeof(cnt));
	for(int j=1;j<(1<<18);++j){
		for(int i=0;i<18;++i){
			if(j&(1<<i)){
				++cnt[1][j];
				q[1][j][cnt[1][j]]=i;
			}
			else{
				++cnt[0][j];
				q[0][j][cnt[0][j]]=i;
			}
		}
	}
}

int main(){
	init();
	while(scanf("%s",s)!=EOF&&s[0]!='0'){
		memset(dp,0x3f,sizeof(dp));
		int n=strlen(s);
		dp[0][0]=0;
		for(int i=0;i<n;++i){
			char pre='A';
			char now=s[i];
			int cost=1;
			if(now>=pre)cost+=min(now-pre,pre+26-now);
			else cost+=min(pre-now,now+26-pre);
			dp[i][1<<i]=cost;
		}
		for(int j=1;j<(1<<n)-1;++j){
			for(int i=1;i<=cnt[1][j]&&q[1][j][i]<n;++i){
				int ii=q[1][j][i];
				char pre=s[ii];
				for(int k=1;k<=cnt[0][j]&&q[0][j][k]<n;++k){
					int kk=q[0][j][k];
					char now=s[kk];
					if(ii<kk){
						int num=0;
						for(int p=ii+1;p<kk;++p)if(j&(1<<p))num++;
						int cost=1;
						if(now>=pre)cost+=min(now-pre,pre+26-now);
						else cost+=min(pre-now,now+26-pre);
						cost+=num;
						if(dp[ii][j]+cost<dp[kk][j+(1<<kk)])dp[kk][j+(1<<kk)]=dp[ii][j]+cost;
					}
					else{
						int num=0;
						for(int p=ii;p>kk;--p)if(j&(1<<p))num++;
						int cost=1;
						if(now>=pre)cost+=min(now-pre,pre+26-now);
						else cost+=min(pre-now,now+26-pre);
						cost+=num;
						if(dp[ii][j]+cost<dp[kk][j+(1<<kk)])dp[kk][j+(1<<kk)]=dp[ii][j]+cost;
					}
				}
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<n;++i){
			if(dp[i][(1<<n)-1]<ans)ans=dp[i][(1<<n)-1];
		}
		printf("%d\n",ans);
	}
	return 0;
}
