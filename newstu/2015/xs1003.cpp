#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=205;

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int abs(int a){return a>=0?a:-a;}

char s[maxn][maxn];
int num[2][maxn][maxn];

int main(){
	int n,m,x;
	while(scanf("%d%d%d",&n,&m,&x)!=EOF){
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(s[i][j]=='*'){
						for(int k=max(1,i-x);k<=min(n,i+x);++k){
						int p1=max(1,j-(x-abs(i-k))),p2=min(m,j+(x-abs(i-k)));
						num[0][k][p1]++;
						num[1][k][p2]--;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			int tmp=0;
			for(int j=1;j<=m;++j){
				tmp+=num[0][i][j];
				if(s[i][j]=='.')ans=max(ans,tmp);
				tmp+=num[1][i][j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
