#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=205;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int a[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n;
		int A,B,l;
		scanf("%d%d%d%d",&n,&A,&B,&l);
		for(int i=1;i<=n;++i){
			scanf("%d%d",&a[2*i-1],&a[2*i]);
		}
		a[0]=0;
		a[2*n+1]=l;
		int minn=0;
		int pre=0;
		for(int i=1;i<=n;++i){
			pre+=(a[2*i-1]-a[2*i-2])*B;
			if(pre<minn)minn=pre;
			pre-=(a[2*i]-a[2*i-1])*A;
			if(pre<minn)minn=pre;
		}
		printf("Case #%d: ",q);
		printf("%d\n",0-minn);
	}
	return 0;
}
