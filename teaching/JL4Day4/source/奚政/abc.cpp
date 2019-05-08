#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("abc.in", "r", stdin);
	freopen("abc.out", "w", stdout);
	int a,b,c,l,r;
	scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
	int ans = 0;
	for(int i = l ; i <= r ; ++ i){
		if(i % a == 0 || i % b == 0 || i % c == 0)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
