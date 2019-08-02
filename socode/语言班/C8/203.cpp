#include <bits/stdc++.h>
using namespace std;

int cnt[105];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		cnt[a] ++;	
	}
	for(int i = 0 ; i <= 100 ; ++ i){
		for(int j = 1 ; j <= cnt[i] ; ++ j){
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
