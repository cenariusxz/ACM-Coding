#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 105;

char s[maxn][maxn];
int cnt[maxn];
int ans[maxn],c = 0;
int n;

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&cnt[i]);
    for(int t = 1 ; t <= n ; ++ t){
        for(int i = 1 ; i <= n ; ++ i){
            if(cnt[i])continue;
            ans[++c] = i;
            for(int j = 1 ; j <= n ; ++ j){
                if(s[i][j] != '0')cnt[j] -- ;
            }
        }
    }
    sort(ans + 1 , ans + c +1);
    printf("%d\n",c);
    for(int i = 1 ; i <= c ; ++ i)printf("%d ",ans[i]);
    printf("\n");
	return 0;
}
