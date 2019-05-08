#include <bits/stdc++.h>
using namespace std;

int num[10];

int main(){
	for(int i = 1 ; i <= 7 ; ++ i){
		int a,b;
		scanf("%d%d",&a,&b);
		num[i] = a+b;
	}
	int Max=0, pos=0;
	for(int i = 1 ; i <= 7 ; ++ i){
		if(num[i] > Max){
			Max = num[i];
			pos = i;
		}
	}
	if(Max <= 8)printf("0\n");
	else printf("%d\n",pos);
	return 0;
}
