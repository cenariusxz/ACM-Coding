#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int ans=0;
		while(n--){
			int a;
			scanf("%d",&a);
			ans^=a;
		}
		if(ans)printf("First player wins.\n");
		else printf("Second player wins.\n");
	}
	return 0;
}
