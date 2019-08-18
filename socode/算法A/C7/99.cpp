#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int a[maxn];

int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    sort(a+1, a+1+n);
    for(int i = 1 ; i <= n ; ++ i){
        int l = i+1 , r = n , ans = -1;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(a[mid] == s - a[i]){
                ans = mid;
                break;
            }
            else if(a[mid] < s - a[i])l = mid+1;
            else r = mid-1;
        }
        if(ans != -1){
            printf("%d %d\n",a[i],a[ans]);
            return 0;    
        }
    }
    printf("-1\n");
    return 0;
}
