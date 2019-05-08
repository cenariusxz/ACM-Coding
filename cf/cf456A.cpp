#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

struct node{
    int a,b;
    bool operator < (const node x)const{
        if(a==x.a)return b < x.b;
        return a<x.a;
    }
}nd[maxn];

int n;

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%d%d",&nd[i].a,&nd[i].b);
    }
    sort(nd + 1, nd + n + 1);
    for(int i = 2 ; i <= n ; ++ i){
        if(nd[i].b < nd[i-1].b){
            printf("Happy Alex\n");
            return 0;
        }
    }
    printf("Poor Alex\n");
    return 0;
}
