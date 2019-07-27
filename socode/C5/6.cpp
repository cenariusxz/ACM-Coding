# include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int ans;
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		if( i == 1 )ans = a;
		else if(a > ans)ans = a;
	}
	printf("%d\n",ans);
	return 0;
}
