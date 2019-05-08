#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 50000 + rand() % 50000;
	int m = 50000 + rand() % 50000;
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d",1 + rand() % 10000);
		if( i == n )printf("\n");
		else printf(" ");
	}
	for(int i = 1 ; i <= m ; ++ i){
		int l = rand() % (n - 1) + 1;
		int r = l + rand() % (n - l);
		printf("%d %d\n",l,r);
	}

	return 0;
}
