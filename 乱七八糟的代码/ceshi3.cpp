//editor: Jan Tang
//problem:
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <time.h>
using namespace std;
#define set0(a) memset(a,0,sizeof(a));
#define CIN(a,n) for(int i=1;i<=n;i++) cin>>a[i];
typedef unsigned long long ull;
typedef int ll;
const int Mod = 1e9+7;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
int m,n;
/*==============================head==========================*/
int main(){
	while(scanf("%d",&n)!=EOF){
		ll t = 1;
		double start = clock();
		for(ll i = 1; i <= n; i++){
			t += i;
			t -= i;
			t *= i;
			t /= i;
		}
		double stop = clock();
		double duration = (double(stop-start))/1000;
		printf("time = %lf\n", duration);
	}
	return 0;
}

