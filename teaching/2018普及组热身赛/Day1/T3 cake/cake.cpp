#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int a[maxn],b[maxn];
ll ans[maxn];

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T3-") + ID[T] + "-l.out").c_str() ,"w",stdout);
//    freopen("T3-1.in","r",stdin);
//    freopen("T3-1.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&b[i]);
    for(int i = 1 ; i <= n ; ++ i)ans[i] = b[i];
    for(int t = 2 ; t <= 3 ; ++ t){
        for(int i = n ; i >= 1 ; -- i){
            ll tmp = INF;
            for(int j = 1 ; j < i ; ++ j){
                if(a[j] < a[i] && ans[j] < tmp)tmp = ans[j];
            }
            if(tmp == INF)ans[i] = INF;
            else ans[i] = tmp + b[i];
        }
    }
    ll res = INF;
    for(int i = 1 ; i <= n ; ++ i)if(ans[i] < res)res = ans[i];
    printf("%lld\n",res);
    }
    return 0;
}
