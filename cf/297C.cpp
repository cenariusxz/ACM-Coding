#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long

int a[100000+5];

int main(){
	int n;
	scanf("%d",&n);
	int i;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	ll ans=0;
	bool f=0;
	ll b;
	for(i=n;i>1;i--){
		if(!f){
			if(a[i]==a[i-1]||a[i]==a[i-1]+1){
				b=a[i-1];
				i--;
				f=1;
			}
		}
		else{
			if(a[i]==a[i-1]||a[i]==a[i-1]+1){
				ans+=b*a[i-1];
				i--;
				f=0;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
