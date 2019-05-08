#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main(){
	int n,ans = INF;
	scanf("%d",&n);
	for(int i = 1 ; i <= 3 ; ++ i){
		int a,b;
		scanf("%d%d",&a,&b);
		int cnt = n/a + (n%a!=0);
		cnt *= b;
		if(cnt < ans)ans = cnt;
	}
	printf("%d\n",ans);
	return 0;
}
