#include <stdio.h>

int T,N;
int A[100];

int main(){
	for(int i = 1; i <= 20; ++i) A[i] = i;
	for(N = 1; N <= 20; ++N){
		int ans = 100;
		for(int s = 0; s < (1 << N); ++s){
			bool flag = false;
			for(int i = 1; i <= N; ++i){
				if((1 << (i - 1)) & s) continue;
				for(int j = i + 1; j <= N; ++j){
					if((1 << (j - 1)) & s) continue;
					for(int k = j + 1; k <= N; ++k){
						if((1 << (k - 1)) & s) continue;
						if(i + j > k) flag = true;
					}
				}
			}
			if(flag == false){
				int res = 0;
				for(int i = 0; i < N; ++i){
					if((1 << i) & s) res++;
				}
				ans = res < ans ? res : ans;
			}
		}
		printf("%d : %d\n",N,ans);
	}
	return 0;
}
