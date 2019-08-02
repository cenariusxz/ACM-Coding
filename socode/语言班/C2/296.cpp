#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	scanf("%d",&a);
	printf("%d\n", a%10);
	printf("%d\n", a/10%10);
	printf("%dk\n", a/100);
	printf("%02d\n", a%100);
	return 0;
}
