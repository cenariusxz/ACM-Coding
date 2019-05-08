#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=5e4+5;
const int INF=0x3f3f3f3f;

int num[5][maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(num,0,sizeof(num));
		int maxx=0;
		for(int i=1;i<=n;++i){
			for(int i=0;i<=4;++i){
				int a;
				scanf("%d",&a);
				num[i][a]++;
				if(a>maxx)maxx=a;
			}
		}
		for(int i=1;i<=maxx;++i){
			
		}
	}
	return 0;
}
