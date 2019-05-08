#include <bits/stdc++.h>
using namespace std;

int a[10],n;

int main(){
	n = 4;
	for(int i = 1 ; i <= n ; ++ i)a[i] = i;
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d ",a[i]);
	}
	printf("\n");
	while(next_permutation(a+1,a+1+n)){
		for(int i = 1 ; i <= n ; ++ i){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}
