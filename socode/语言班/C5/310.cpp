# include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		if(x == a)cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
