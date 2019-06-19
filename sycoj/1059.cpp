#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int n;
int a[maxn];

int main(){
	while(scanf("%d",&n) != EOF){
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
		int sum = 0, Max = 0;
		for(int i = 1 ; i <= n ; ++ i)Max = max(Max, a[i]);
		for(int i = 1 ; i <= n ; ++ i)sum += a[i];
		if(2*Max > sum)printf("%.1lf\n",sum - 1.0*Max);
		else printf("%.1lf\n",sum/2.0);
	}
	return 0;
}


