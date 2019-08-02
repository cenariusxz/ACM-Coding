#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	scanf("%d",&a);
	if( a%3 == 0  &&  a%5 == 0  &&  a%7 == 0){
		printf("Yes\n");
	}
	else{
		printf("%d\n", a/(3*5*7));	
	}
	return 0;
}
