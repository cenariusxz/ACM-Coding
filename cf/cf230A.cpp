#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

struct node{
    int x,y;
    bool operator < (const node a)const{
        return x < a.x;
    }
}nd[maxn];

int main(){
    int s,n;
    scanf("%d%d",&s,&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&nd[i].x,&nd[i].y);
    sort(nd + 1 , nd + n + 1);
    for(int i = 1 ; i <= n ; ++ i){
        if(s <= nd[i].x){
            printf("NO\n");
            return 0;
        }
        else s += nd[i].y;
    }
    printf("YES\n");
    return 0;
}
