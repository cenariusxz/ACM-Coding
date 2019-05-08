#include <bits/stdc++.h>
using namespace std;

int a[15];

int main(){
	for(int i = 1 ; i <= 10 ; ++ i)scanf("%d",&a[i]);
	int x;
	scanf("%d",&x);
	int ans = 0;
	for(int i = 1 ; i <= 10 ; ++ i){
		if(a[i] <= x+30)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
