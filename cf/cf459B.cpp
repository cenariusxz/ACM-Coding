#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int n;
int a[maxn];

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%d",&a[i]);
    }
    sort(a + 1, a + n + 1);
    int p1 = 0,p2 = 0;
    for(int i = 1 ; i <= n ; ++ i){
        if(a[i] == a[1])p1++;
        if(a[i] == a[n])p2++;
    }
    if(a[1]==a[n])printf("%d %lld\n",0,n*(ll)(n-1)/2);
    else printf("%d %lld\n",a[n]-a[1],p1*(ll)p2);
    return 0;
}
