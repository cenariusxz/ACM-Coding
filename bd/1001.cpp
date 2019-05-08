#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll a[10005];

int main(){
	int T,i;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		ll maxx=m;
		bool f=1;
		if(a[1]>maxx)f=0;
		for(i=1;i<n&&f;i++){
			if(a[i+1]>maxx){
				maxx=a[i]+k;
				if(a[i+1]>maxx)f=0;
				if(k)k--;
			}
		}		
		printf("Case #%d:\n",q);
		if(f)printf("why am I so diao?");
		else printf("madan!");
		printf("\n");
		
	}
	return 0;
}
