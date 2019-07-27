#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib(int x){
	if(x == 1 || x == 2)return 1;
	return fib(x-1) + fib(x-2);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%lld\n",fib(n));
	return 0;
}
