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
const int MAXN = 1000010;

int T;
int t[MAXN],n;
int pos[100010],sufmax[100010];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(pos,0,sizeof(pos));
		for(int i = 1; i <= n; ++i){
			scanf("%d",&t[i]);
			pos[t[i]] = i;
		}
		sufmax[100000] = pos[100000];
		for(int i = 99999; i >= 1; --i){
			sufmax[i] = max(sufmax[i + 1],pos[i]);
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			ans = max(ans,sufmax[t[i] + 1] - i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
