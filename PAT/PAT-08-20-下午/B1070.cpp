#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;

int len[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i)scanf("%d",&len[i]);
	sort(len + 1, len + n + 1);
	double ans = len[1];
	for(int i = 2 ; i <= n ; ++i){
		ans = ( ans + len[i] ) / 2.0;
	}
	printf("%d\n",(int)ans);
	return 0;
}
