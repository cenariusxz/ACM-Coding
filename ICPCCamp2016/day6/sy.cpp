#include <stdio.h>

typedef long long ll;

ll C[110][110];
ll pw[110];

int main(){
	for(int i = 1; i <= 100; ++i){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	pw[0] = 1;
	for(int i = 1; i <= 60; ++i){
		pw[i] = pw[i - 1] * 2;
	}
	for(int b = 1; b <= 60; ++b){
		double ans = 1.0 * C[b][b / 2] / pw[b];
		printf("%.4f\n",ans);
	}
	return 0;
}

