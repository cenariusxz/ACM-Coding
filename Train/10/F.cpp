#include <stdio.h>
#include <math.h>

int T,L;
double ans[1600];

void Pre(){
	ans[1] = 1;
	double a = 0.5;
	double c = 1,d = 2;
	int cnt = 0;
	for(int i = 2; i <= 1500; ++i){
		ans[i] = ans[i - 1] + a;
		cnt++;
		//printf("a : %.6f\n",a);
		if(cnt % 2 == 0){
			c += 2;
			d += 2;
			a *= c / d;
		}
	}
}

int main(){
	Pre();
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d",&L);
		printf("Case %d: %.6f\n",tt,ans[L]);
	}
	return 0;
}
