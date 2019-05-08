#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 2000000 + rand()%2000000;
	int k = n/2;
	printf("%d %d\n",n,k);
	for(int i = 1 ; i <= n ; ++ i){
		if(i <= n - 10)printf("%d",1 + rand()%10);
		else printf("%d",1 + rand()%10000);
		if(i == n)printf("\n");
		else printf(" ");
	}
	return 0;
}
