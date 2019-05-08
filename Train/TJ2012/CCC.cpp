#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int INF=0x3f3f3f3f;

int dp[1010][110];
char s[1010],t[1010];

int main(){
	while(scanf("%s%s",s+1,t+1)!=EOF){
		int n=strlen(s+1);
		if(n==1){
			int d=abs(s[1]-t[1]);
			d=min(d,10-d);
			printf("%d\n",d);
			continue;
		}
		s[n+1]=s[n+2]=s[n+3]='0';
		t[n+1]=t[n+2]=t[n+3]='0';
		memset(dp,0x3f,sizeof(dp));
		dp[1][(s[1]-'0')*10+(s[2]-'0')]=0;
		for(int i=1;i<=n;++i){
			for(int now=0;now<=99;++now){
				if(dp[i][now]==INF)continue;
				int a=now/10,b=now%10;
				int dif[2];
				dif[0]=t[i]-'0'-a;
				dif[1]=dif[0]>0?dif[0]-10:10+dif[0];
				for(int f=0;f<2;++f){
					int d;
					if(dif[f]>=0)d=1;
					else d=-1;
					for(int j=0;;j+=d){
						for(int k=0;;k+=d){
							int nxtb=(b+j+10)%10;
							int nxtc=(s[i+2]-'0'+k+10)%10;
							dp[i+1][nxtb*10+nxtc]=min(dp[i+1][nxtb*10+nxtc],dp[i][now]+abs(dif[f]));
							if(k==j)break;
						}
						if(j==dif[f])break;
					}
				}
			}
		}
		printf("%d\n",dp[n+1][0]);
	}
	return 0;
}
