#include <stdio.h>

int main(){
	int T,N;
	int ans[100] = {0,0,0,0,1,1,2,3,3,4,5,6,7,7,8,9,10,11,12,13,14};
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d",&N);
		printf("Case #%d: %d\n",tt,ans[N]);
	}
	return 0;
}
