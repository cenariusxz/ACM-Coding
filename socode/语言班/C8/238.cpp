#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(){ 
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i){
		int k = i;
		for(int j = i + 1 ; j <= n ; ++ j){
			if(a[j] < a[k])k = j;
		}
		int t = a[k];
		a[k] = a[i];
		a[i] = t;
	}
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d ",a[i]);	
	}
	printf("\n");
	return 0; 
} 
