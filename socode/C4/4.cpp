#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a + b > c && a + c > b && b + c > a){
		int aa = a * a;
		int bb = b * b;
		int cc = c * c;
		if(aa + bb == cc || aa + cc == bb || bb + cc == aa){
			printf("Yes Yes\n");	
		}
		else printf("Yes\n");
	}
	else printf("No\n");
	
	return 0;	
}
