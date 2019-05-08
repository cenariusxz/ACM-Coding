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
		int a=0,sum=0;
		for(int i=1;i<=n;++i){
			int num;
			scanf("%d",&num);
			if(num>0)++a;
			else num=-num;
			sum+=num;
		}
		printf("Case %d: ",q);
		if(a){
			int g=__gcd(a,sum);
			printf("%d/%d\n",sum/g,a/g);
		}
		else printf("inf\n");
	}
	return 0;
}
