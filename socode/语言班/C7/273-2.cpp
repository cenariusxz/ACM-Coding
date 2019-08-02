#include <bits/stdc++.h>
using namespace std;

int cnt[10005],n,x;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		cnt[a] ++;	
	}
	scanf("%d",&x);
	printf("%d\n",cnt[x]);
	return 0;
}
