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

int T,n,m;
int sg[1 << 20];

int Solve(int p,int s){
    if(sg[s] != -1) return sg[s];
    int f = 0;
    int ps[20] = {0},used[30] = {0};
    for(int i = 19; i >= 0; --i){
        if(s & (1 << i)){
            ps[i] = i;
            if(i < 19 && (s & (1 << (i + 1)))){
                ps[i] = ps[i + 1];
            }
        }
    }
    for(int i = 0; i < 20; ++i) if(s & (1 << i)){
        if(ps[i] + 1 < 20){
			int ts = s;
			ts -= (1 << i);
			ts += (1 << (ps[i] + 1));
            used[Solve(p,ts)] = 1;
        }
    }
	for(int i = 0; i < 30; ++i) if(used[i] == 0){
		f = i;
		break;
	}
    return sg[s] = f;
}

void Pre(){
    memset(sg,-1,sizeof(sg));
    sg[0] = 0;
    for(int p = 0; p < 20; ++p){
        int s = 0,ts = 0;
        for(int i = 0; i <= p; ++i){
            s |= (1 << i);
            ts |= (1 << (19 - i));
        }
        sg[ts] = 0;
        Solve(p,s);
    }
}

int main(){
    Pre();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d",&m);
            int s = 0;
            for(int j = 1; j <= m; ++j){
                int a;
                scanf("%d",&a);
                s |= (1 << (a - 1));
            }
            ans ^= sg[s];
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
