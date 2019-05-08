#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxn=1005;

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

int a[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int aa,b;
			scanf("%d%d",&aa,&b);
			int ans=-1;
			for(int i=aa;i<=b;++i)if(a[i]>ans)ans=a[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}

