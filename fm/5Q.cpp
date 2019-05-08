#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef unsigned long long ull;

ull C[40][40];

void init(){
	for(int i=0;i<=40;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i&&j)?(C[i-1][j]+C[i-1][j-1]):1;
		}
	}
}

int main(){
	init();
	int n,a,b;
	while(scanf("%d%d%d",&n,&a,&b)!=EOF){
		ull ans=0;
		ull ans1=0,ans2=0;
		for(int i=0;i<=min(n,a);++i){
			ans1+=C[n][i]*C[a][i];
		}
		for(int i=0;i<=min(n,b);++i){
			ans2+=C[n][i]*C[b][i];
		}
	//	printf("%lld %lld %lld\n",ans1,ans2,ans1*ans2);
	//	ans1=C[a+n][n];
	//	ans2=C[b+n][n];
		printf("%I64u\n",ans1*ans2);
	}
	return 0;
}
