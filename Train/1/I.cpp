#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i){
		double a,b,c,d;
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		if(d>7){
			printf("0\n");
			continue;
		}
		if((a<=56&&b<=45&&c<=25)||(a+b+c<=125)){
			
			printf("1\n");
			ans++;
		}
		else {
			printf("0\n");

		}
	}
	printf("%d\n",ans);
}
