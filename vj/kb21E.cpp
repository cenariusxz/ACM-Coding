#include<stdio.h>
#include<string.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		long double p1=1,p2=1;
		int ans=0;
		while(1){
			p1*=(n-ans);
			p2*=n;
			ans++;
			if(p1*2<=p2)break;
		}
		printf("Case %d: %d\n",q,ans-1);
	}
	return 0;
}
