#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n==1)printf("YES\n");
		else if(__gcd(2*n-2,k)==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
