#include <bits/stdc++.h>
using namespace std;

int num[10] = {6,8,4,2};

int main(){
	int n;
	scanf("%d",&n);
	if(n)printf("%d\n",num[n%4]);
	else printf("1\n");
	return 0;
}
