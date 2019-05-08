#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

int M[55][55];
int n,m;
ll ans=0;
int now[100];

bool check(int cnt){
	for(int i=1;i<cnt;++i){
		for(int j=i+1;j<cnt;++j){
			int a=now[i],b=now[j],c=now[cnt];
			if(M[a][b]==M[a][c]&&M[a][b]==M[b][c])return 1;
		}
	}
	return 0;
}

void dfs(int s,int cnt){
	for(int i=s;i<n;++i){
		now[cnt]=i;
		if(cnt>=3){
			if(check(cnt)){
				ans=(ans+(1ll<<(n-i-1))%mod)%mod;
				continue;
			}
		}
		dfs(i+1,cnt+1);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		ans=0;
		memset(M,0,sizeof(M));
		scanf("%d%d",&n,&m);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			a--;b--;
			M[a][b]=M[b][a]=1;
		}
		dfs(0,1);
		printf("Case #%d: %lld\n",q,ans);
	}
	return 0;
}
