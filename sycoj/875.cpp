#include <bits/stdc++.h>
using namespace std;

int num[10005];

void init(){
	for(int i = 1 ; i <= 10000 ; ++ i)num[i] = num[i-1] + i;
}

int main(){
	init();
	int n;
	scanf("%d",&n);
	int p1;
	for(p1 = 1 ; p1 <= 10000 ; ++ p1){
		if(num[p1] >= n)break;
	}
	int sum = p1+1;
	int id = n - num[p1-1];
	if(p1 % 2)printf("%d/%d\n",sum-id,id);
	else printf("%d/%d\n",id,sum-id);
	return 0;
}

