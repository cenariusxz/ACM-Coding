#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main(){
	int n,k,l,c,d,p,nl,np;
	scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
	int ans = INF;
	ans = min(ans, k*l/nl/n);
	ans = min(ans, c*d/n);
	ans = min(ans, p/np/n);
	printf("%d\n",ans);
	return 0;
}
