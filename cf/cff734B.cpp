#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int main(){
    int k2,k3,k5,k6;
    scanf("%d%d%d%d",&k2,&k3,&k5,&k6);
    printf("%d\n", min(k2,min(k5,k6) ) * 256 + min( k3, k2-min(k2,min(k5,k6) ) )*32);
    return 0;
}
