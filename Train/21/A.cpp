#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

ll L,P,V;

int main(){
	int tt = 0;
	while(scanf("%lld%lld%lld",&L,&P,&V) != EOF){
		if(L == 0 && P == 0 && V == 0) break;
		ll ans = V / P * L;
		ll tmp = V % P;
		ans += min(tmp,L);
		printf("Case %d: %lld\n",++tt,ans);
	}
	return 0;
}
