#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int pow_2[64];
//30
int main(){
	int T;
	pow_2[0]=1;
	for(int i=1;i<=31;++i){
		pow_2[i]=pow_2[i-1]*2;
	}
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=0;
		for(int i=min(m,30);i>=0;--i){
			ans+=n/pow_2[i];
			n%=pow_2[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
