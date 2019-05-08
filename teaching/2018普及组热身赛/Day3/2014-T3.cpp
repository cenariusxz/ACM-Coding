#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int x = min(a, min(n-a+1, min(b,n-b+1)));
	int sum = 0;
	for(int i = 1 ; i < x ; ++ i){
		sum += 4*n + 4 - 8*i;
	}
	if(a == x){
		printf("%d\n",sum+b-x+1);
	}
	else if(b == n-x+1){
		sum += n-2*x+1;
		printf("%d\n",sum+a-x+1);
	}
	else if(a == n-x+1){
		sum += 2*(n-2*x+1);
		printf("%d\n",sum+n-x-b+2);
	}
	else{
		sum += 3*(n-2*x+1);
		printf("%d\n",sum+n-x-a+2);
	}
	return 0;
}
