#include <bits/stdc++.h>
using namespace std;

int main(){
	srand((unsigned)time(NULL));
	printf("1000\n");
	for(int tt = 1; tt <= 1000; ++tt){
		int n = 10000,m = rand() % 100000 + 1;
		printf("%d %d\n",n,m);
		for(int i = 1; i <= n;  ++i){
			printf("%d ",rand() % 100000 + 1);
		}
		puts("");
	}
	return 0;
}
