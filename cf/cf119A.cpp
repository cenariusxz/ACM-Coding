﻿#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main(){
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    int ans = 1;
    while(n){
        n -= __gcd(n,a);
        swap(a,b);
        ans ^= 1;
    }
    printf("%d\n",ans);
    return 0;
}