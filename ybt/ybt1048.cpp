#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int cnt = 0;
	if(a < 60)cnt++;
	if(b < 60)cnt++;
	printf("%d\n",cnt == 1);
	return 0;
}
