#include "bits/stdc++.h"
using namespace std;
int main(){
	int a=0,b=0,i,c,d,h=0,max=0;
	for(i = 0;i <= 6 ;i++){
		scanf("%d%d",&a,&b);
		if(a+b>8 and a+b>max)h=i,max=a+b;
	}
	if(h>0)printf("%d",h);
	else printf("0\n");
	return 0;
}
