#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e4 + 5;

int n,c[maxn],y[maxn];
int ans[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&c[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&y[i]);
	int Min = INF, id = 0;
	for(int i = 1 ; i <= n ; ++ i){
		Min ++;
		if(Min > c[i])Min = c[i], id = i;
		ans[id] += y[i];
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
