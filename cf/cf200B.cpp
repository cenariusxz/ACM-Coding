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
    int n;
    scanf("%d",&n);
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        int a;
        scanf("%d",&a);
        ans += a;
    }
    printf("%.10lf\n",ans*1.0/n);
    return 0;
}
