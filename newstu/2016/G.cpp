#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	ll pre,now,tmp;
	scanf("%d",&n);
	printf("2\n");
	if(n>=2){
		pre=2;
		for(int i=2;i<=n;++i){
			now=i*(ll)(i+1)*(i+1);
			printf("%lld\n",now-pre/i);
			pre=i*(ll)(i+1);
		}
	}
	return 0;
}
