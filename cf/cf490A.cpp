#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int p[4][maxn],cnt[4];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i){
        int id;
        scanf("%d",&id);
        p[id][++cnt[id]] = i;
    }
    printf("%d\n",min(cnt[1],min(cnt[2],cnt[3])));
    for(int i = 1 ; i <= min(cnt[1],min(cnt[2],cnt[3])) ; ++ i){
        printf("%d %d %d\n",p[1][i],p[2][i],p[3][i]);
    }
	return 0;
}
