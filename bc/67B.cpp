#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-10;

double dp[100][100];
double dp2[100][100];
int ans[100][100];
double x[100];

char s[10];

void init(){
	memset(ans,0,sizeof(ans));
	for(int a=2;a<=20;++a){
		for(int b=2;b<=20;++b){
			memset(dp,0,sizeof(dp));
			memset(dp2,0,sizeof(dp2));
			memset(x,0,sizeof(x));
			dp[0][a]=1;
			dp2[0][b]=1;
			for(int i=2;i<=b;++i)x[i]+=1;
			for(int i=0;i<=19;++i){
				if(i>0){
					for(int j=b+i;j<=21;++j){
						for(int k=b+i-1;k<j;++k){
							double tmp=0;
							if(j-k>10)continue;
							if(j-k<10)tmp=dp2[i-1][k]/13;
							else tmp=dp2[i-1][k]*4/13;
							dp2[i][j]+=tmp;
							for(int p=k+1;p<=j;++p)x[p]+=tmp;
						}
					}
				}
			}
			for(int i=0;i<=19;++i){
				double num=0;
				if(i>0){
					for(int j=a+i;j<=21;++j){
						for(int k=a+i-1;k<j;++k){
							if(j-k>10)continue;
							if(j-k<10)dp[i][j]+=dp[i-1][k]/13;
							else dp[i][j]+=dp[i-1][k]*4/13;
						}
					}
				}
				double ss=0;
				for(int j=a+i;j<=21;++j)ss+=dp[i][j];
				num=1-ss;
				for(int j=a+i;j<=21;++j){
					num+=x[j]*dp[i][j];
				}
				if(num<0.5){
					ans[a][b]=1;
					break;
				}
			}

		}
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int a=0,b=0;
		scanf("%s",s);
		if(s[0]=='T')a+=10;
		else if(s[0]=='A')a+=1;
		else a+=s[0]-'0';
		if(s[1]=='T')a+=10;
		else if(s[1]=='A')a+=1;
		else a+=s[1]-'0';
		if(s[2]=='T')b+=10;
		else if(s[2]=='A')b+=1;
		else b+=s[2]-'0';
		if(s[3]=='T')b+=10;
		else if(s[3]=='A')b+=1;
		else b+=s[3]-'0';
		if(ans[a][b])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
