#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans = 1;
	int a,b;
	scanf("%d%d",&a,&b);
	if(a > b)swap(a,b);
	for(int i = 1 ; i <= a ; ++ i)ans *= i;
	printf("%d\n",ans);
	return 0;
}
