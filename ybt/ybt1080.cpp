#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int x = 2 ; ; ++ x){
		if(a % x == b % x && a % x == c % x){
			printf("%d\n",x);
			break;
		}
	}
	return 0;
}
