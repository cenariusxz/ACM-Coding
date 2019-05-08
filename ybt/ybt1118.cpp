#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

int a[maxn],b[maxn],g[maxn],k[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
	}
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i = n ; i >= 1 ; -- i){
		if(x >= a[i] && x <= a[i] + g[i] - 1 && 
				y >= b[i] && y <= b[i] + k[i] - 1){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
