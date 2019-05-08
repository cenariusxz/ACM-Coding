#include <stdio.h>
#include <string.h>

int main(){
	int n = 400;
	int top = n * (n - 1) / 2;
	int sum = 0;
	for(int i = 1; i <= 400; ++i){
		int j1 = top - i * (i - 1) / 2;
		int j2 = (n + i + 1) * (n - i) / 2;
		printf("%d : %d\n",i,j2 - j1 + 1);
		sum += j2 - j1 + 1;
	}
	printf("%d\n",sum);
	return 0;
}
