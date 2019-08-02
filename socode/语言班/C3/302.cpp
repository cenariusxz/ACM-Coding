#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a < 60 && b >= 60 && c >= 60)printf("%d\n",a);
	else if(a >= 60 && b < 60 && c >= 60)printf("%d\n",b);
	else if(a >= 60 && b >= 60 && c < 60)printf("%d\n",c);
	else printf("No.\n");
	return 0;
}
