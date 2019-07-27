#include <bits/stdc++.h>
using namespace std;

int num[10005],n,x;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
	scanf("%d",&x);
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(a[i] == x)cnt++;	
	}
	printf("%d\n",cnt);
	return 0;
}
