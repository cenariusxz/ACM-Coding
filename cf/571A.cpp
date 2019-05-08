#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int main(){
	int a,b,c,l;
	scanf("%d%d%d%d",&a,&b,&c,&l);
	if(a<b){
		int t=a;
		a=b;
		b=t;
	}
	if(a<c){
		int t=a;
		a=c;
		c=t;
	}
	if(b<c){
		int t=b;
		b=c;
		c=t;
	}
	ll ans=0;
	for(int i=0;i<=min(l,(b+c+l-a-1)/2);++i){
		printf("%d\n",i);
		int mi=max(0,a+i-b-c+1);
		int ma=l-i;
		int m=l-i;
		ans+=(a+i+c+m-b)/2-(c+m-b-a-i+1)/2+1;
		printf("a%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}
