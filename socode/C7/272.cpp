#include <bits/stdc++.h>
using namespace std;

int num[10005],n;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
	for(int i = n ; i >= 1 ; -- i){
		printf("%d",num[i]);
		if(i == 1)printf("\n");
		else printf(" ");
	}
	return 0;
}
