#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int ans1 = 0, ans2 = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			ans1 += min(n-i+1,m-j+1);
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			ans2 += (n-i+1)*(m-j+1);
		}
	}
	printf("%d %d\n",ans1,ans2-ans1);
	return 0;
}
