#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		double ans=0;
		for(int i=1;i<=n;++i){
			ans+=n*1.0/i;
		}
		printf("Case %d: %.10lf\n",q,ans);
	}
	return 0;
}
