#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;

int main(){
	ll l,r;
	while(scanf("%lld%lld",&l,&r)!=EOF){
		if(l==r){
			if(l==0||l==1)printf("0\n");
			else if(l==2)printf("1\n");
			else printf("2\n");
			continue;
		}
		if(r<=1){
			printf("0\n");
			continue;
		}
		if(r<=2){
			printf("1\n");
			continue;
		}
		if(r<=l+2){
			printf("2\n");
			continue;
		}
		if(l==0){
			printf("%lld\n",(r+1)/2);
		}
		else{
			printf("%lld\n",2+(r-l-2)/2);
		}
	}
	return 0;
}
