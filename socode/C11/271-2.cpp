#include <bits/stdc++.h>
using namespace std;

void fun(int n){
	int a;
	scanf("%d", &a);
	if(n > 1)fun(n-1);
	printf("%d ",a);
}

int main(){
	int n;
	scanf("%d",&n);
	fun(n);
	printf("\n");
	return 0;	
}
