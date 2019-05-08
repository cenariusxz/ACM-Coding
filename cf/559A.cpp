#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int a[10];

int main(){
	int i,j;
	ll ans=0;
	for(i=1;i<=6;i++){
		scanf("%d",&a[i]);
	}
	bool f1=1,f2=1;
	ll pos=a[1]+a[1]+1;
	for(i=1;i<=a[2]+a[3];i++){
		ans+=pos;
		if(f1)pos++;
		else pos--;
		if(f2)pos++;
		else pos--;
		if(i==a[2]){
			f1=0;
			pos--;
		}
		if(i==a[6]){
			f2=0;
			pos--;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
