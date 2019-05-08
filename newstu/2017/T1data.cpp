#include <bits/stdc++.h>
using namespace std;

int main(){
//	freopen("T1-2.in","w",stdout);
	int n,m;
	n = 500000 + rand()%500000;
	m = 1000 + rand()%1000;
	printf("%d %d\n",n,m);
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d",rand()%10000);
		if(i == n)printf("\n");
		else printf(" ");
	}
	for(int i = 1 ; i <= m ; ++ i){
		int t = rand() % 2;
		int l = rand() % (n / 2);
		int r = l + ( n / 2 ) - 1;
		r += rand() % (n - r + 1);
		printf("%d %d %d\n",t,l,r);
	}
	return 0;
}
