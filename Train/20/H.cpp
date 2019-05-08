#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;
const int mod=21092013;
const int INF=0x3f3f3f3f;

char s[maxn],t[maxn],tmp[maxn],ind[maxn];
int dp[maxn],sum[maxn],num[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%s%s",s,t);
		int pos=0;
		for(int i=0;s[i];++i){
			if(s[i]=='U'){
				if(pos)pos--;
			}
			else tmp[pos++]=s[i];
		}
		tmp[pos]=0;
//		printf("%d\n",pos);
		int cnt=0;
		for(int i=0;t[i];++i){
			if(t[i]=='U'){
				if(cnt<pos)++cnt;
				else t[i]='A';
			}
		}
		cnt=0;
		for(int i=0;t[i];++i){
			if(t[i]!='A')t[cnt++]=t[i];
		}
		t[cnt]=0;
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		int sl=1,sr=1;
		for(int i=cnt-1;i>=0;--i){
			if(t[i]=='L'){
				dp[i]=sl;
				sr+=dp[i];
				if(sr>=mod)sr-=mod;
			}
			if(t[i]=='R'){
				dp[i]=sr;
				sl+=dp[i];
				if(sl>=mod)sl-=mod;
			}
		}
//		printf("%s %s\n",tmp,t);
//		for(int i=0;i<cnt;++i)printf("%d ",dp[i]);
//		printf("\n");
		for(int i=cnt-1;i>=0;--i){
			sum[i]=sum[i+1]+dp[i];
			if(sum[i]>=mod)sum[i]-=mod;
		}
//		for(int i=0;i<=cnt;++i)printf("%d ",sum[i]);
//		printf("\n");
		cnt=pos-1;
		for(int i=0;t[i];++i){
			if(t[i]=='U')ind[i]=tmp[cnt--];
		}
		int pl=INF,pr=INF;
		for(int i=strlen(t)-1;i>=0;--i){
			if(t[i]=='U'){
				if(ind[i]=='L')num[i]=pr;
				else num[i]=pl;
//				printf("%d %c %d\n",i,ind[i],num[i]);
			}
			else if(t[i]=='L')pl=i;
			else pr=i;
		}
		int ans=sum[0]+1;
//		printf("%d\n",ans);
		if(ans>=mod)ans-=mod;
		for(int i=0;t[i];++i){
			if(t[i]=='U'){
				ans++;
				if(ans>=mod)ans-=mod;
				if(num[i]!=INF){
					ans=(ans+sum[num[i]+1]+1)%mod;
//					printf("%d %d\n",num[i],sum[num[i]+1]);
				}
			}
		}
		printf("Case %d: %d\n",q,ans);
	}
	return 0;
}
