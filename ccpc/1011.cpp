#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

char s[maxn];
int vis[30];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%s",s);
		memset(vis,0,sizeof(vis));
		int n=strlen(s);
		for(int i=0;i<n;++i)vis[s[i]-'a']=1;
		int ans=0;
		for(int i=0;i<=26;++i)if(vis[i])ans++;
		printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}
