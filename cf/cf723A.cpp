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
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)swap(a,b);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    printf("%d\n",c-a);
    return 0;
}