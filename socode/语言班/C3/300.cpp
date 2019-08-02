#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if( a >= 70 && b >= 70 && c >= 70)printf("2\n");
	else if( a >= 60 && b >= 60 && c >= 60)printf("1\n");
	else printf("0\n");
	return 0;
}
