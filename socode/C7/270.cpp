#include <bits/stdc++.h>
using namespace std;

int num[105];

int main(){
	long long a;
	scanf("%lld",&a);
	if(a == 0)printf("0\n");
	else{
		int cnt = 0;
		while(a){
			num[++cnt] = a%2;
			a /= 2;	
		}
		for(int i = cnt ; i >= 1 ; -- i){
			printf("%d",num[i]);	
		}
		printf("\n");
	}
	return 0;	
}
