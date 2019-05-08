#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char s[1005][1005];

int a[1005][1005];

int ans[1005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(s[i][j]=='1'){
					a[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(a[i][j]==1){
					int mm=min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]));
					a[i][j]=a[i][j]+mm;
					ans[a[i][j]]++;
				}
			}
		}
		for(int i=n;i>=1;--i){
			ans[i]+=ans[i+1];
		}
		while(m--){
			int q;
			scanf("%d",&q);
			printf("%d\n",ans[q]);
		}
	}
	return 0;
}
