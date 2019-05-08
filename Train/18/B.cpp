#include <stdio.h>

int n,k;

int main(){
	while(scanf("%d%d",&n,&k) != EOF){
		int ans1 = 0,ans2 = 0;
		for(int i = 1; i <= n; ++i){
			int a;
			scanf("%d",&a);
			if(a >= k){
				ans1 += a - k;
			}
			else{
				ans2 += k - a;
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
